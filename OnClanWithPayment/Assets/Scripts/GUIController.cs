using UnityEngine;
using System.Collections;

public class GUIController : MonoBehaviour {

	float ScreenWidth;
	float ScreeHeight;

	// Use this for initialization
	void Start () {
	
		#if UNITY_IPHONE
		//AppotaSDKHandler.Instance.Init("e8a1ffd03bfe5d401d875df633cd43eb051f0a4fc", "060f9c20e5259e2462f1cc00c15c6f93051f0a4fc", "1e1aa54ce3c646d8f6456558434d9475051f74156", "game_state","http://api.appota.com/notice_url","http://api.appota.com/config_file/config.json");
		AppotaSDKHandler.Instance.Init();
		// Need this function for callback
		AppotaSDKHandler.Instance.SetDelegate();
		#endif
		#if UNITY_ANDROID
		AppotaSDKHandler.Instance.Init();
		//AppotaSDKHandler.Instance.Init ("1e1aa54ce3c646d8f6456558434d9475051f74156", "ac9859fe645780570adeefd0a062d8f4051f0a4fc", "http://appota.com/notice_url", "https://developer.appota.com/config.php");
		//AppotaSDKHandler.Instance.SetAutoShowLogin(false);
		#endif
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	
	void OnGUI () {
		// Make a background box
		//GUI.Box(new Rect(10,10,200,130), "Onclan");

		ScreenWidth = Screen.width;
		ScreeHeight = Screen.height;

		GUIStyle customButton = new GUIStyle("button");
		customButton.fontSize = 30;
		
		if(GUI.Button(new Rect(ScreenWidth / 3, 40,ScreenWidth / 3,ScreeHeight / 10), "Login", customButton)) {
			AppotaSDKHandler.Instance.ShowLoginView ();
		}
		
		if(GUI.Button(new Rect(ScreenWidth / 3, 50 + ScreeHeight / 10,ScreenWidth / 3,ScreeHeight / 10), "Logout", customButton)) {
			AppotaSDKHandler.Instance.Logout ();
		}

		if(AppotaSDKHandler.Instance.IsUserLogin()){

			if(GUI.Button(new Rect(ScreenWidth / 3, 60 + 2 * ScreeHeight / 10,ScreenWidth / 3,ScreeHeight / 10), "Switch Account", customButton)) {
				AppotaSDKHandler.Instance.SwitchAccount ();
			}
			
			if(GUI.Button(new Rect(ScreenWidth / 3, 70 + 3 * ScreeHeight / 10,ScreenWidth / 3,ScreeHeight / 10), "User Info", customButton)) {
				AppotaSDKHandler.Instance.ShowUserInfo ();
			}
			
			if(GUI.Button(new Rect(ScreenWidth / 3, 80 + 4 * ScreeHeight / 10,ScreenWidth / 3,ScreeHeight / 10), "Make Payment", customButton)) {
				AppotaSDKHandler.Instance.MakePayment ();
			}
		}
	}
}
