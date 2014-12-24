﻿using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class OnClanSDKHandler {
	private string appotaApiKey;
	private string onClanUser;
	private string userID;
	private bool isInitOnClanHandler;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	private static OnClanSDKHandler _instance;

	// Singleton for SDK handler
	public static OnClanSDKHandler Instance
	{
		get
		{
			if(_instance == null) _instance = new OnClanSDKHandler();
			return _instance;
		}
	}

	#if UNITY_IPHONE
	// Support On Clan
	[DllImport("__Internal")]
	private static extern void _OCSDKPostScore(int score);
	
	[DllImport("__Internal")]
	private static extern void _OCSDKPostScoreToCategory(int score, string categoryID);
	
	[DllImport("__Internal")]
	private static extern void _OCSDKShowLeaderBoard();
	
	[DllImport("__Internal")]
	private static extern void _OCSDKMakePayment();
	
	[DllImport("__Internal")]
	private static extern void _OCSDKConfigure(string apiKey);

	[DllImport("__Internal")]
	private static extern bool _OCSDKCheckUserLoggedIn();
	
	[DllImport("__Internal")]
	private static extern string _OCSDKGetUserInfo();
	
	[DllImport("__Internal")]
	private static extern void _OCSDKSetChatHeadDragable(bool value);
	
	[DllImport("__Internal")]
	private static extern void _OCSDKSetChatHeadBoucingEdge(bool value);
	
	[DllImport("__Internal")]
	private static extern void _OCSDKSetChatHeadPosition(float x, float y);
	
	[DllImport("__Internal")]
	private static extern void _OCSDKSetLogoutButtonHidden(bool value);

	public void PostScore(int score){
		Debug.Log ("Start posting score");
		_OCSDKPostScore (score);
	}
	
	public void ShowLeaderBoard() {
		Debug.Log ("Start show leader board score");
		_OCSDKShowLeaderBoard ();
	}
	
	public void ConfigureOCSDK() {
		OnClanSDKReceiver.InitializeGameObjects();
		appotaApiKey = AppotaSetting.InAppApiKey;
		if(!OnClanSDKHandler.IsInitOnClanHandler){
			_OCSDKConfigure (appotaApiKey);
			OnClanSDKHandler.IsInitOnClanHandler  = true;
		}
	}	
	
	public string GetUserInfo() {
		return _OCSDKGetUserInfo ();
	}
	
	public void SetChatHeadDragable(bool value) {
		_OCSDKSetChatHeadDragable (value);
	}
	
	public void SetChatHeadBoucingEdge(bool value) {
		_OCSDKSetChatHeadBoucingEdge (value);
	}
	
	public void SetChatHeadPosition(float x, float y) {
		_OCSDKSetChatHeadPosition (x, y);
	}
	
	public void EnableLogout(bool value) {
		_OCSDKSetLogoutButtonHidden (!value);
	}

	#endif

	#if UNITY_ANDROID
	
	public void PostScore(int score){
		AndroidJavaObject obj = new AndroidJavaObject("com.onclan.android.core.UnityHandler");
		Debug.Log("Unity: Score: " + score);
		// Call init sdk here
		object[] args = new object[2];
		args [0] = AppotaSetting.LeaderboardID;
		args [1] = score;
		obj.CallStatic ("SubmitScore", args);
	}
	
	public void ShowLeaderBoard() {
		Debug.Log ("Start show leader board score");
		AndroidJavaObject obj = new AndroidJavaObject("com.onclan.android.core.UnityHandler");
		// Call init sdk here
		object[] args = new object[0];
		obj.CallStatic ("ShowLeaderBoard", args);
	}

	public void SwitchAccount(string onClanUser) {
		Debug.Log ("Start switchAccount");
		AndroidJavaObject obj = new AndroidJavaObject("com.onclan.android.core.UnityHandler");
		// Call init sdk here
		object[] args = new object[1];
		args[0] = onClanUser;
		obj.CallStatic ("SwitchAccount", args);
	}

	public void ConfigureOCSDK() {
		if(!OnClanSDKHandler.IsInitOnClanHandler){
			Debug.Log ("Appota: Start configure android class");

			AndroidJavaObject obj = new AndroidJavaObject("com.onclan.android.core.UnityHandler");
			// Call init sdk here
			OnClanSDKReceiver.InitializeGameObjects();
			object[] args = new object[2];
			string[] type = {"HOME","CHAT", "LEADERBOARD"};
			args[0] = OnClanSDKHandler.OnClanUser;
			args[1] = type;
			Debug.Log ("Appota: Call static android");

			obj.CallStatic ("InitWithPayment", args);
			OnClanSDKHandler.IsInitOnClanHandler = true;
		}
	}	
	
	public void EnableLogout(bool enableLogout) {
		AndroidJavaObject obj = new AndroidJavaObject("com.onclan.android.core.UnityHandler");
		object[] args = new object[1];
		args [0] = enableLogout;
		obj.CallStatic ("EnableLogout", args);
	}

	public void Logout() {
		AndroidJavaObject obj = new AndroidJavaObject("com.onclan.android.core.UnityHandler");

		object[] args = new object[0];
		obj.CallStatic ("Logout", args);
	}

	#endif

	public static bool IsInitOnClanHandler
	{
		get { return Instance.isInitOnClanHandler; }
		set
		{
			if (Instance.isInitOnClanHandler != value)
			{
				Instance.isInitOnClanHandler = value;
			}
		}
	}
	
	public static string OnClanUser
	{
		get { return Instance.onClanUser; }
		set
		{
			if (Instance.onClanUser != value)
			{
				Instance.onClanUser = value;
			}
		}
	}

	public static string UserID
	{
		get { return Instance.userID; }
		set
		{
			if (Instance.userID != value)
			{
				Instance.userID = value;
			}
		}
	}
}
