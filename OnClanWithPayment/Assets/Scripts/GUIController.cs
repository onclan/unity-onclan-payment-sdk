using UnityEngine;
using System.Collections;

public class GUIController : MonoBehaviour {

	float ScreenWidth;
	float ScreeHeight;

	// Use this for initialization
	void Start () {
	
		#if UNITY_IPHONE
		AppotaSDKHandler.Instance.Init();
		// Need this function for callback
		//AppotaSDKHandler.Instance.SetDelegate();
		#endif
		#if UNITY_ANDROID
		AppotaSDKHandler.Instance.Init();
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
