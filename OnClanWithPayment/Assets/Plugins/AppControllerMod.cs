using UnityEngine;
using System.IO;

public class AppControllerMod 
{
    public static void UpdateUnityAppController(string path)
    {
        const string filePath = "Classes/UnityAppController.mm";
        string fullPath = Path.Combine(path, filePath);
        
        var reader = new StreamReader(fullPath);
        string textAppController = reader.ReadToEnd();
        reader.Close();
        
        int fixupStart = textAppController.IndexOf("openURL:", System.StringComparison.Ordinal);
        if(fixupStart <= 0)
            return;
        int fixupMid = textAppController.IndexOf("return", fixupStart);
        if(fixupMid <= 0)
            return;
        int fixupEnd = textAppController.IndexOf(';', fixupMid);
        if(fixupEnd <= 0)
            return;
        
        string fixedAppController = textAppController.Substring(0, fixupMid);
		fixedAppController += "[AppotaGameSDKConfigure handleOpenURL:url sourceApplication:sourceApplication annotation:annotation];\n[OCSDKConfigure handleOpenURL:url sourceApplication:sourceApplication annotation:annotation];\nreturn true;";
        fixedAppController += textAppController.Substring(fixupEnd+1);

		// Add header import
		int finalFixupStart = fixedAppController.IndexOf("#import <OpenGLES/EAGL.h", System.StringComparison.Ordinal);
		if(finalFixupStart <= 0)
			return;
		int finalFixupEnd = fixedAppController.IndexOf(">", finalFixupStart);
		if(finalFixupEnd <= 0)
			return;
        
		string finalFixedAppController = fixedAppController.Substring(0, finalFixupStart);
		finalFixedAppController += "#import <AppotaSDK/AppotaSDK.h>\n#import <OnClanSDK/OCSDK.h>\n#import <OpenGLES/EAGL.h>";
		finalFixedAppController += fixedAppController.Substring(finalFixupEnd+1);

        var writer = new StreamWriter(fullPath, false);
		writer.Write(finalFixedAppController);
        writer.Close();
        
    }

}
