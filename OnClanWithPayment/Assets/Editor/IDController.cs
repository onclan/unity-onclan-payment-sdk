using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;

[CustomEditor(typeof(AppotaSetting))]
public class IDController : EditorWindow {

	static string _facebookID;
	static string _facebookSecretID;
	static string _twitterKey;
	static string _twitterSecret;
	static string _googleID;
	static string _googleSecretID;
	static string _clientID;
	static string _clientSecret;
	static string _inAppApiKey;
	static string _leaderboardID;
	static string _sandboxApiKey;
	static string _paymentState;
	static string _noticeURL;
	static string _configURL;
	static bool _isUseSandbox;
	private AppotaSetting instance;

    public Texture2D appotaLogo;

    private static IDController windows;
    void OnEnable()
    {
        appotaLogo = Resources.LoadAssetAtPath("Assets/Appota/Resources/appota_logo.png", typeof(Texture2D)) as Texture2D;

        
    }
	[MenuItem ("Appota/Appota Setting")]
	static void Init(){

	    windows = GetWindow(typeof (IDController), false, "Appota", true) as IDController;

	    windows.minSize = new Vector2(400, 620);
        windows.maxSize = new Vector2(600, 620);
        windows.Show();

	    EditorWindow.GetWindow(typeof (IDController)).Show();

		_isUseSandbox = AppotaSetting.IsUsingSandbox;
		_facebookID = AppotaSetting.FacebookAppID;
		_facebookSecretID = AppotaSetting.FacebookAppSecretID;
		_twitterKey = AppotaSetting.TwitterConsumerKey;
		_twitterSecret = AppotaSetting.TwitterConsumerSecret;
		_googleID = AppotaSetting.GoogleClientId;
		_googleSecretID = AppotaSetting.GoogleClientSecretId;
		_clientID = AppotaSetting.ClientID;
		_clientSecret = AppotaSetting.ClientSecret;
		_inAppApiKey = AppotaSetting.InAppApiKey;
		_leaderboardID = AppotaSetting.LeaderboardID;
		_sandboxApiKey = AppotaSetting.SandboxApiKey;
		_paymentState = AppotaSetting.PaymentState;
		_noticeURL = AppotaSetting.NoticeURL;
		_configURL = AppotaSetting.ConfigURL;
	}

	void OnGUI()
	{
		GUILayout.Label(appotaLogo,GUILayout.MaxHeight(120), GUILayout.MaxWidth(400));

	    //GUILayout.Space(20);

	    EditorGUILayout.BeginVertical();

	    if (PenaltyEditorTools.DrawHeader("OnClan Settings"))
	    {
            _inAppApiKey = EditorGUILayout.TextField("API Key", _inAppApiKey);
			_sandboxApiKey = EditorGUILayout.TextField("Sandbox Api Key", _sandboxApiKey);
			_clientID = EditorGUILayout.TextField("Client ID", _clientID);
			_clientSecret = EditorGUILayout.TextField("Client Secret", _clientSecret);
			_leaderboardID = EditorGUILayout.TextField("Leaderboard ID", _leaderboardID);
			if (_isUseSandbox) GUI.backgroundColor = Color.green; else GUI.backgroundColor = Color.white;
			
			_isUseSandbox = EditorGUILayout.Toggle("Using Sandbox",_isUseSandbox);
	        GUI.backgroundColor = Color.white;
	    }

        GUILayout.Space(10);

	    if (PenaltyEditorTools.DrawHeader("Social Settings"))
	    {
			_facebookID = EditorGUILayout.TextField("Facebook ID", _facebookID);
			#if UNITY_WP8
			_facebookSecretID = EditorGUILayout.TextField("Facebook Secret ID", _facebookSecretID);
			#endif
			_twitterKey = EditorGUILayout.TextField("Twitter Key", _twitterKey);
			_twitterSecret = EditorGUILayout.TextField("Twitter Secret", _twitterSecret);
			_googleID = EditorGUILayout.TextField("Google Client ID", _googleID);
			_googleSecretID = EditorGUILayout.TextField("Google Client Secret ID", _googleSecretID);
	    }
        GUILayout.Space(20);

		if (PenaltyEditorTools.DrawHeader("Payment Settings"))
		{
			
			_paymentState = EditorGUILayout.TextField("Payment State", _paymentState);
			_noticeURL = EditorGUILayout.TextField("Notice URL",_noticeURL);
			_configURL = EditorGUILayout.TextField("Config URL", _configURL);
		}
		
		GUILayout.Space(20);

        EditorGUILayout.EndVertical();

	    EditorGUILayout.BeginHorizontal();
        Color myStyleColor = new Color(190f / 255, 240f / 255, 143f / 255);
	    GUI.backgroundColor = myStyleColor;

        if (GUILayout.Button("Update Setting!", GUILayout.ExpandWidth(true), GUILayout.MinWidth(250), GUILayout.MinHeight(50)))
        {

            SaveSetting();
        }
        GUILayout.Space(10);
	    GUI.backgroundColor = Color.white;

        if (GUILayout.Button("Cancel!", GUILayout.ExpandWidth(true), GUILayout.MinWidth(100), GUILayout.MinHeight(50)))
	    {
            windows.Close();
	        //Cancel Setting;
	    }
        
        EditorGUILayout.EndHorizontal();

    }

    //Save or Update Settings Data

    void SaveSetting()
    {
		AppotaSetting.FacebookAppID = _facebookID;
		AppotaSetting.FacebookAppSecretID = _facebookSecretID;
		AppotaSetting.TwitterConsumerKey = _twitterKey;
		AppotaSetting.TwitterConsumerSecret = _twitterSecret;
		AppotaSetting.GoogleClientId = _googleID;
		AppotaSetting.GoogleClientSecretId = _googleSecretID;
		AppotaSetting.InAppApiKey = _inAppApiKey;
		AppotaSetting.ClientID = _clientID;
		AppotaSetting.LeaderboardID = _leaderboardID;
		AppotaSetting.ClientSecret = _clientSecret;
		AppotaSetting.PaymentState = _paymentState;
		AppotaSetting.SandboxApiKey = _sandboxApiKey;
		AppotaSetting.NoticeURL = _noticeURL;
		AppotaSetting.ConfigURL = _configURL;
		AppotaSetting.IsUsingSandbox = _isUseSandbox;
        ManifestMod.GenerateManifest();
        Debug.Log("Complete setting!!!");
        
    }

}
