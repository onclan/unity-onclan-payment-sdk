using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.XCodeEditor;
#endif
using System.IO;

public static class XCodePostProcess
{

#if UNITY_EDITOR
	[PostProcessBuild(999)]
	public static void OnPostProcessBuild( BuildTarget target, string pathToBuiltProject )
	{
		if (target != BuildTarget.iPhone) {
			Debug.LogWarning("Target is not iPhone. XCodePostProcess will not run");
			return;
		}

		string OnClanBundlePath = Application.dataPath + "/Editor/XUPorter/Mods/iOS/Appota/OnClanBundle.bundle";
		string OnClanFrameworkPath = Application.dataPath + "/Editor/XUPorter/Mods/iOS/Appota/OnClanSDK.framework";
		string AppotaBundlePath = Application.dataPath + "/Editor/XUPorter/Mods/iOS/Appota/AppotaBundle.bundle";
		string AppotaFrameworkPath = Application.dataPath + "/Editor/XUPorter/Mods/iOS/Appota/AppotaSDK.framework";
		string FacebookFrameworkPath = Application.dataPath + "/Editor/XUPorter/Mods/iOS/Appota/FacebookSDK.framework";
		
		if (!Directory.Exists(OnClanBundlePath) || !Directory.Exists(OnClanFrameworkPath) || !Directory.Exists(FacebookFrameworkPath) || !Directory.Exists(AppotaBundlePath) || !Directory.Exists(AppotaFrameworkPath)){
			EditorUtility.DisplayDialog("Warning", "Missing frameworks! Please read documents again and put all necessary frameworks in folder: \nAssets/Editor/XUPorter/Mods/iOS/Appota/", "Ok");
			return;
		}

		// Create a new project object from build target
		XCProject project = new XCProject( pathToBuiltProject );

		// Find and run through all projmods files to patch the project.
		// Please pay attention that ALL projmods files in your project folder will be excuted!
		string[] files = Directory.GetFiles( Application.dataPath, "*.projmods", SearchOption.AllDirectories );
		foreach( string file in files ) {
			UnityEngine.Debug.Log("ProjMod File: "+file);
			project.ApplyMod( file );
		}

		// Config while building project
		PlistMod.UpdatePlist(pathToBuiltProject, AppotaSetting.ClientID, AppotaSetting.FacebookAppID, AppotaSetting.TwitterConsumerKey, AppotaSetting.TwitterConsumerSecret, AppotaSetting.GoogleClientId, AppotaSetting.GoogleClientSecretId);
		AppControllerMod.UpdateUnityAppController(pathToBuiltProject);

		//TODO implement generic settings as a module option
		project.overwriteBuildSetting("CODE_SIGN_IDENTITY[sdk=iphoneos*]", "iPhone Distribution", "Release");
		
		// Finally save the xcode project
		project.Save();

	}
#endif

	public static void Log(string message)
	{
		UnityEngine.Debug.Log("PostProcess: "+message);
	}
}
