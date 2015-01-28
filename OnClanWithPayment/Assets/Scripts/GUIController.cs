using UnityEngine;
using System.Collections;

public class GUIController : MonoBehaviour {

	float ScreenWidth;
	float ScreenHeight;
	string text = "UserID: ";
	string gameState = "Game State";

	// Use this for initialization
	void Start () {
	
		#if UNITY_IPHONE
		AppotaSDKHandler.Instance.Init();
		#endif
		#if UNITY_ANDROID
		AppotaSDKHandler.Instance.Init();
		AppotaSDKHandler.Instance.SetAutoShowLogin(false);
		#endif
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	
	void OnGUI () {
	
		ScreenWidth = Screen.width;
		ScreenHeight = Screen.height;

		GUIStyle customButton = new GUIStyle("button");
		customButton.fontSize = 30;
		
		if(GUI.Button(new Rect(ScreenWidth / 3, 40,ScreenWidth / 3,ScreenHeight / 10), "Login", customButton)) {
			AppotaSDKHandler.Instance.ShowLoginView ();
		}
		
		if(GUI.Button(new Rect(ScreenWidth / 3, 50 + ScreenHeight / 10,ScreenWidth / 3,ScreenHeight / 10), "Logout", customButton)) {
			AppotaSDKHandler.Instance.Logout ();
		}

		gameState = GUI.TextField(new Rect(ScreenWidth / 3, 60 + 2 * ScreenHeight / 10,ScreenWidth / 3,ScreenHeight / 10), gameState, 30);
		if(GUI.Button(new Rect(ScreenWidth / 3, 70 + 3 * ScreenHeight / 10,ScreenWidth / 3,ScreenHeight / 10), "Update Game State", customButton)) {
			AppotaSDKHandler.Instance.SetState (gameState);
		}

		text = "UserID: " + AppotaSDKHandler.Instance.GetUserID();
		GUI.TextArea(new Rect(10, 40, ScreenWidth / 4, ScreenHeight / 10), text, 200, customButton);

		if(AppotaSDKHandler.Instance.IsUserLogin()){
			
			if(GUI.Button(new Rect(ScreenWidth / 3, 80 + 4 * ScreenHeight / 10,ScreenWidth / 3,ScreenHeight / 10), "User Info", customButton)) {
				AppotaSDKHandler.Instance.ShowUserInfo ();
			}
			
			if(GUI.Button(new Rect(ScreenWidth / 3, 90 + 5 * ScreenHeight / 10,ScreenWidth / 3,ScreenHeight / 10), "Make Payment", customButton)) {
				AppotaSDKHandler.Instance.MakePayment ();
			}
		}
	}
}
