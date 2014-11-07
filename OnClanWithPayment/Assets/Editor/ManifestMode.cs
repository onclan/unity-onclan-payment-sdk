using UnityEngine;
using System.IO;
using System.Xml;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;

public class ManifestMod
{
	public const string LoginActivityName = "com.appota.facebook.LoginActivity";
	public const string ApplicationIdMetaDataName = "com.facebook.sdk.ApplicationId";
	public const string TwitterKeyMetaDataName = "com.appota.twitter.consumer.key";
	public const string TwitterSecretMetaDataName = "com.appota.twitter.consumer.secret";
	public const string OnClanAPIKeyMetaDataName = "com.appota.apiKey";
	public const string OnClanGameIDMetaDataName = "com.onclan.gameId";

	public static void GenerateManifest()
	{
		var outputFile = Path.Combine(Application.dataPath, "Plugins/Android/AndroidManifest.xml");
		
		// only copy over a fresh copy of the AndroidManifest if one does not exist
		if (!File.Exists(outputFile))
		{
			Debug.LogError("AndroidManifest.xml missing!!! Please put it in Assets/Plugin/Android.");
		}
		UpdateManifest(outputFile);
	}
	
	private static XmlNode FindChildNode(XmlNode parent, string name)
	{
		XmlNode curr = parent.FirstChild;
		while (curr != null)
		{
			if (curr.Name.Equals(name))
			{
				return curr;
			}
			curr = curr.NextSibling;
		}
		return null;
	}
	
	private static XmlElement FindElementWithAndroidName(string name, string androidName, string ns, string value, XmlNode parent)
	{
		var curr = parent.FirstChild;
		while (curr != null)
		{
			if (curr.Name.Equals(name) && curr is XmlElement && ((XmlElement)curr).GetAttribute(androidName, ns) == value)
			{
				return curr as XmlElement;
			}
			curr = curr.NextSibling;
		}
		return null;
	}
	
	public static void UpdateManifest(string fullPath)
	{
		XmlDocument doc = new XmlDocument();
		doc.Load(fullPath);
		
		if (doc == null)
		{
			Debug.LogError("Couldn't load " + fullPath);
			return;
		}
		
		XmlNode manNode = FindChildNode(doc, "manifest");
		XmlNode dict = FindChildNode(manNode, "application");
		
		if (dict == null)
		{
			Debug.LogError("Error parsing " + fullPath);
			return;
		}

		// Change name product
		((XmlElement)dict).SetAttribute("android:label", UnityEditor.PlayerSettings.productName);
		
		string ns = dict.GetNamespaceOfPrefix("android");

		//add the login activity
		XmlElement loginElement = FindElementWithAndroidName("activity", "name", ns, LoginActivityName, dict);
		if (loginElement == null)
		{
			loginElement = CreateLoginElement(doc, ns);
			dict.AppendChild(loginElement);
		}

		//add the app id
		//<meta-data android:name="com.facebook.sdk.ApplicationId" android:value="\ 409682555812308" />
		XmlElement appIdElement = FindElementWithAndroidName("meta-data", "name", ns, ApplicationIdMetaDataName, dict);
		if (appIdElement == null)
		{
			appIdElement = doc.CreateElement("meta-data");
			appIdElement.SetAttribute("name", ns, ApplicationIdMetaDataName);
			dict.AppendChild(appIdElement);
		}
		appIdElement.SetAttribute("value", ns, "\\ " + AppotaSetting.FacebookAppID); // stupid hack to be string format

		//add the TwitterConsumerKey
		//<meta-data android:name="com.appota.gamesdk.twitter.consumer.key" android:value="YOUR_CONSUMER_KEY" />
		XmlElement TwitterKeyElement = FindElementWithAndroidName("meta-data", "name", ns, TwitterKeyMetaDataName, dict);
		if (TwitterKeyElement == null)
		{
			TwitterKeyElement = doc.CreateElement("meta-data");
			TwitterKeyElement.SetAttribute("name", ns, TwitterKeyMetaDataName);
			dict.AppendChild(TwitterKeyElement);
		}
		TwitterKeyElement.SetAttribute("value", ns, "" + AppotaSetting.TwitterConsumerKey); 

		//add the TwitterConsumerSecret
		//<meta-data android:name="com.appota.gamesdk.twitter.consumer.secret" android:value="YOUR_SECRET_KEY" />
		XmlElement TwitterSecretElement = FindElementWithAndroidName("meta-data", "name", ns, TwitterSecretMetaDataName, dict);
		if (TwitterSecretElement == null)
		{
			TwitterSecretElement = doc.CreateElement("meta-data");
			TwitterSecretElement.SetAttribute("name", ns, TwitterSecretMetaDataName);
			dict.AppendChild(TwitterSecretElement);
		}
		TwitterSecretElement.SetAttribute("value", ns, "" + AppotaSetting.TwitterConsumerSecret);  

		// Add OnClanApiID
		XmlElement OnClanElement = FindElementWithAndroidName("meta-data", "name", ns, OnClanAPIKeyMetaDataName, dict);
		if (OnClanElement == null)
		{
			OnClanElement = doc.CreateElement("meta-data");
			OnClanElement.SetAttribute("name", ns, OnClanAPIKeyMetaDataName);
			dict.AppendChild(OnClanElement);
		}
		OnClanElement.SetAttribute("value", ns, "" + AppotaSetting.InAppApiKey);  

		// Add OnClanGameID
		XmlElement OnClanGameIDElement = FindElementWithAndroidName("meta-data", "name", ns, OnClanGameIDMetaDataName, dict);
		if (OnClanGameIDElement == null)
		{
			OnClanGameIDElement = doc.CreateElement("meta-data");
			OnClanGameIDElement.SetAttribute("name", ns, OnClanGameIDMetaDataName);
			dict.AppendChild(OnClanGameIDElement);
		}
		OnClanGameIDElement.SetAttribute("value", ns, "" + AppotaSetting.GameID); 

		// Edit Sandbox meta
		XmlElement SandboxElement = FindElementWithAndroidName("meta-data", "name", ns, "sandbox", dict);
		if (SandboxElement == null)
		{
			SandboxElement = doc.CreateElement("meta-data");
			SandboxElement.SetAttribute("name", ns, "sandbox");
			dict.AppendChild(SandboxElement);
		}
		string _isUsingSandbox = "" + AppotaSetting.IsUsingSandbox; // Need parse "True" or "False" to "true" or "false"
		SandboxElement.SetAttribute("value", ns, _isUsingSandbox.ToLower()); 

		Debug.Log("Complete setting manifest!!!");
		
		doc.Save(fullPath);
	}
	
	private static XmlElement CreateLoginElement(XmlDocument doc, string ns)
	{
		//<activity android:name="com.facebook.LoginActivity" android:theme="@android:style/Theme.Translucent.NoTitleBar" android:label="@string/app_name" />
		XmlElement activityElement = doc.CreateElement("activity");
		activityElement.SetAttribute("name", ns, LoginActivityName);
		activityElement.SetAttribute("label", ns, "@string/app_name");
		activityElement.SetAttribute("theme", ns, "@android:style/Theme.Translucent.NoTitleBar");
		activityElement.InnerText = "\n    ";  //be extremely anal to make diff tools happy
		return activityElement;
	}
}
