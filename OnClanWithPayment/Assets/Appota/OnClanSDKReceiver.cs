using UnityEngine;
using System.Collections;

public class OnClanSDKReceiver : MonoBehaviour {
	private static bool initialized;
	private static GameObject playGameObject;	

	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		
	}
	
	private static OnClanSDKReceiver _instance;
	
	// Singleton for SDK handler
	public static OnClanSDKReceiver Instance
	{
		get
		{
			if(_instance == null) _instance = new OnClanSDKReceiver();
			return _instance;
		}
	}
	
	
	public static void InitializeGameObjects()
	{
		if(!initialized)
		{
			playGameObject = new GameObject("OnClanSDKReceiver");
			playGameObject.AddComponent(typeof(OnClanSDKReceiver));
			//keep this game object around for all scenes
			DontDestroyOnLoad(playGameObject);
			initialized = true;
			Debug.Log("Did start init game object");
		}
	}
	
	public void OnLoginSuccess(string appotaSession)
	{
		Debug.Log ("OnClanSDKReceiver: Did login");
		Debug.Log(appotaSession);
	}
	
	public void OnLogoutSuccess()
	{ 
		Debug.Log ("OnClanSDKReceiver: Did logout");
		if(AppotaSDKHandler.Instance.IsUserLogin())
			AppotaSDKHandler.Instance.Logout();
	}
	
	public void OnPaymentSuccess(string transactionResult)
	{
		Debug.Log ("OnClanSDKReceiver: Did payment");
		Debug.Log(transactionResult);
		//		var jsonResult = SimpleJSON.JSON.Parse (transactionResult);
		if (transactionResult != null) {
			int amount = int.Parse (transactionResult);
			int coin = PlayerPrefs.GetInt ("coin");
			PlayerPrefs.SetInt ("coin", coin + amount);
		}
		//		
	}
	
	public void OnSwitchAccountSuccess(string appotaSession)
	{
		Debug.Log ("Did switch account");
		Debug.Log(appotaSession);
	}
	
	// Support OnClan SDK
	public void onCaptureScreen(string filePath) {
		Debug.Log ("Capture at " + filePath);
		Application.CaptureScreenshot(filePath);	
	}
	
	public void onOpenSDK(string openKey) {
		// Hanle Pause game here
		Debug.Log ("OnClanSDKReceiver: Open SDK called");	
	}

	// Receive score in json format
	public void onReceiveScore(string score) {
		Debug.Log ("Get score " + score);
	}
}
