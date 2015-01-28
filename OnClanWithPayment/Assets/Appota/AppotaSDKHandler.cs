using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System;

public class AppotaSDKHandler {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

	}

	private static AppotaSDKHandler _instance;

	// Singleton for SDK handler
	public static AppotaSDKHandler Instance
	{
		get
		{
			if(_instance == null) _instance = new AppotaSDKHandler();
			return _instance;
		}
	}

#if UNITY_IPHONE
    
	[DllImport("__Internal")]
	private static extern void configSDK(string clientId, string clientSecret, string inAppApiKey, string paymentState, string noticeURL, string configURL);

	[DllImport("__Internal")]
	private static extern void setGoogleClientId(string id);

	[DllImport("__Internal")]
	private static extern void setOnlyOpenProfile(bool isOnlyOpenProfile);

	[DllImport("__Internal")]
	private static extern void setShowCloseLoginView(bool isShowCloseLoginView);

	[DllImport("__Internal")]
	private static extern void setAutoShowPaymentButton(bool autoShowPaymentButton);

	[DllImport("__Internal")]
	private static extern void setDelegate();

	[DllImport("__Internal")]
	private static extern void setJsonConfigUrl(string url);

	[DllImport("__Internal")]
	private static extern void logoutSDK();

	[DllImport("__Internal")]
	private static extern void showSwitchUserView();

	[DllImport("__Internal")]
	private static extern void showPaymentView();

	[DllImport("__Internal")]
	private static extern void closePaymentView();

	[DllImport("__Internal")]
	private static extern void hidePaymentButton();

	[DllImport("__Internal")]
	private static extern void showPaymentButton();

	[DllImport("__Internal")]
	private static extern void showUserInfoView();

	[DllImport("__Internal")]
	private static extern void showLoginView();

	[DllImport("__Internal")]
	private static extern void setAutoShowLogin(bool autoShowLogin);

	[DllImport("__Internal")]
	private static extern void setPaymentState(string paymentState);

	[DllImport("__Internal")]
	private static extern bool isUserLogin();

	[DllImport("__Internal")]
	private static extern string getUserID();

	public void Init(){
		Init (AppotaSetting.ClientID, AppotaSetting.ClientSecret, AppotaSetting.InAppApiKey, AppotaSetting.PaymentState, AppotaSetting.NoticeURL, AppotaSetting.ConfigURL);
	}

	public void Init(string clientId, string clientSecret, string inAppApiKey, string paymentState, string noticeURL, string configURL) {

		if(string.IsNullOrEmpty(clientId)){
			Debug.LogError("Missing Client ID. Please check your ID Setting.");
		} else
		if (string.IsNullOrEmpty(clientSecret)){
			Debug.LogError("Missing Client Secret ID. Please check your ID Setting.");
		} else 
		if (string.IsNullOrEmpty(inAppApiKey)){
			Debug.LogError("Missing ApiKey. Please check your ID Setting.");
		} else 
		if (string.IsNullOrEmpty(paymentState)){
			paymentState = "";
		} else 
		if (string.IsNullOrEmpty(noticeURL)){
			Debug.LogError("Missing NoticeUrl. Please check your ID Setting.");
		} else 
		if (string.IsNullOrEmpty(configURL)){
			Debug.LogError("Missing ConfigUrl. Please check your ID Setting.");
		}

		AppotaSDKReceiver.InitializeGameObjects ();
		configSDK (clientId, clientSecret, inAppApiKey, paymentState, noticeURL, configURL);
		// Custom AppotaSDKConfig
		setOnlyOpenProfile(true);
		setShowCloseLoginView(true);
		setAutoShowPaymentButton(false);
		AppotaSDKHandler.Instance.SetDelegate();
	}

	// Need this function for callback
	public void SetDelegate(){
		setDelegate();
	}

	public void SetGoogleClientId(string id){
		setGoogleClientId(id);
	}

	public void SetJsonConfigUrl(string url){
		setJsonConfigUrl(url);
	}

	public void Logout() {
		logoutSDK ();
	}
	
	public void SwitchAccount()
	{
		showSwitchUserView ();
	}
	
	public void MakePayment()
	{
		showPaymentView ();
	}

	public void ClosePaymentView()
	{
		closePaymentView();
	}

	public void ShowPaymentButton()
	{
		showPaymentButton();
	}

	public void HidePaymentButton()
	{
		hidePaymentButton();
	}

	public void ShowUserInfo()
	{
		showUserInfoView ();
	}

	public void ShowLoginView()
	{
		showLoginView();
	}

	public void SetAutoShowLogin(bool autoShowLogin) {
		setAutoShowLogin(autoShowLogin);
	}

	public void SetState(string paymentState) {
		setPaymentState(paymentState);
	}

	public bool IsUserLogin() {
		return isUserLogin();
	}

	public string GetUserID() {
		return getUserID();
	}

#endif
#if UNITY_ANDROID
	private AndroidJavaClass cls_AppotaUnityHandler;

	public void Init(){

		Init (AppotaSetting.InAppApiKey, AppotaSetting.SandboxApiKey, AppotaSetting.NoticeURL, AppotaSetting.ConfigURL);

	}

	public void Init(string apiKey, string sandboxApiKey, string noticeURL, string configURL) {

		if(string.IsNullOrEmpty(apiKey)){
			Debug.LogError("Missing Apikey. Please check your ID Setting.");
		} else
		if(string.IsNullOrEmpty(sandboxApiKey)){
			sandboxApiKey = "";
		} else
		if (string.IsNullOrEmpty(noticeURL)){
			Debug.LogError("Missing NoticeUrl. Please check your ID Setting.");
		} else 
		if (string.IsNullOrEmpty(configURL)){
			Debug.LogError("Missing ConfigUrl. Please check your ID Setting.");
		}

		AppotaSDKReceiver.InitializeGameObjects ();
		AndroidJNI.AttachCurrentThread ();
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		Debug.Log("Start init Android");
		object[] args = new object[4];
		args [0] = configURL;
		args [1] = noticeURL;
		args [2] = apiKey;
		args [3] = sandboxApiKey;
		Debug.Log("Called init Android " + args[0]);
		cls_AppotaUnityHandler.CallStatic("Init", args);
		Debug.Log("Called init Android ");
	}

	public void Logout() {
		Debug.Log ("Start logout");
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		cls_AppotaUnityHandler.CallStatic("LogoutAndUnlinkAccount");
	}

	public void SwitchAccount()
	{
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		cls_AppotaUnityHandler.CallStatic("SwitchAccount");
	}
	
	public void MakePayment()
	{
		Debug.Log ("Start Unity make payment");
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		cls_AppotaUnityHandler.CallStatic("MakePayment");
	}
	
	public void ShowUserInfo()
	{
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		cls_AppotaUnityHandler.CallStatic("ShowUserInfo");
	}

	public void ShowLoginView()
	{
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		cls_AppotaUnityHandler.CallStatic("ShowLoginView");
	}

	public void SetAutoShowLogin(bool autoShowLogin) {
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		Debug.Log("Set auto showlogin " + autoShowLogin);
		object[] args = new object[1];
		args [0] = autoShowLogin;
		cls_AppotaUnityHandler.CallStatic("SetAutoShowLogin", args);
	}

	public bool IsUserLogin() {
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		return cls_AppotaUnityHandler.CallStatic<bool>("IsUserLogin");
	}

	public string GetUserID() {
		return OnClanSDKHandler.UserID;
	}

	public void SetState(string paymentState) {
		cls_AppotaUnityHandler = new AndroidJavaClass("com.appota.gamesdk.unity.UnityHandler");
		object[] args = new object[1];
		args [0] = paymentState;
		cls_AppotaUnityHandler.CallStatic("SetState", args);
	}
#endif

	
#if UNITY_WP8
	
	public delegate void AppotaSDK();
	public AppotaSDK _Init = null;
	public AppotaSDK _Logout = null;
	public AppotaSDK _SwitchAccount	= null;
	public AppotaSDK _MakePayment	= null;
	public AppotaSDK _ShowUserInfo	= null;
	public AppotaSDK _ShowLoginView	= null;
	public Action<bool> _SetAutoShowLogin	= null;


	public void Init(){

		if(string.IsNullOrEmpty(AppotaSetting.InAppApiKey)){
			Debug.LogError("Missing Apikey. Please check your ID Setting.");
		} else
		if (string.IsNullOrEmpty(AppotaSetting.NoticeURL)){
			Debug.LogError("Missing NoticeUrl. Please check your ID Setting.");
		} else 
		if (string.IsNullOrEmpty(AppotaSetting.ConfigURL)){
			Debug.LogError("Missing ConfigUrl. Please check your ID Setting.");
		}

		if (_Init != null)
		{
			_Init();
		}
	}

	public void Logout() {
		if (_Logout != null)
		{
			_Logout();
		}
	}
	
	public void SwitchAccount()
	{
		if (_SwitchAccount != null)
		{
			_SwitchAccount();
		}
	}
	
	public void MakePayment()
	{
		if (_MakePayment != null)
		{
			_MakePayment();
		}
	}
	
	public void ShowUserInfo()
	{
		if (_ShowUserInfo != null)
		{
			_ShowUserInfo();
		}
	}
	
	public void ShowLoginView()
	{
		if (_ShowLoginView != null)
		{
			_ShowLoginView();
		}
	}
	
	public void SetAutoShowLogin(bool isAutoShowLogin) {
		if (_SetAutoShowLogin != null)
		{
			_SetAutoShowLogin(isAutoShowLogin);
		}
	}
	
	
	#endif
}
