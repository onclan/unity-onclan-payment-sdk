using UnityEngine;
using System.Collections;

public class AppotaSDKReceiver : MonoBehaviour {
	private static GameObject playGameObject;
	private static bool initialized;
	
	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		
	}

	private static AppotaSDKReceiver _instance;
	
	// Singleton for SDK handler
	public static AppotaSDKReceiver Instance
	{
		get
		{
			if(_instance == null) _instance = new AppotaSDKReceiver();
			return _instance;
		}
	}


	public static void InitializeGameObjects()
	{
		if(!initialized)
		{
			playGameObject = new GameObject("AppotaSDKReceiver");
			playGameObject.AddComponent(typeof(AppotaSDKReceiver));
			//keep this game object around for all scenes
			DontDestroyOnLoad(playGameObject);
			initialized = true;
		}
	}

	public void GetOnClanUser(string OnClanUser)
	{
		Debug.Log("Appota" + OnClanUser);
		OnClanSDKHandler.OnClanUser = OnClanUser;
    }

	public void OnLoginSuccess(string appotaSession)
	{
		Debug.Log ("AppotaSDKReceiver: Did login");
		Debug.Log("AppotaSDKReceiver: Appota: " + appotaSession);
		OnClanSDKHandler.Instance.ConfigureOCSDK();
	}
	
	public void OnLogoutSuccess()
	{ 
		#if UNITY_ANDROID
		OnClanSDKHandler.Instance.Logout();
		#endif

		OnClanSDKHandler.IsInitOnClanHandler = false;
		Debug.Log ("AppotaSDKReceiver: Did logout");
	}
	
	public void OnPaymentSuccess(string transactionResult)
	{
		Debug.Log ("AppotaSDKReceiver: Did payment");
		Debug.Log("AppotaSDKReceiver: Appota: " + transactionResult);
	}
	
	void OnSwitchAccountSuccess(string appotaSession)
	{
		#if UNITY_ANDROID
		OnClanSDKHandler.Instance.SwitchAccount(OnClanSDKHandler.OnClanUser);
		#endif

		Debug.Log ("AppotaSDKReceiver: Did switch account");
		Debug.Log("AppotaSDKReceiver: Appota: " + appotaSession);

	}
}
