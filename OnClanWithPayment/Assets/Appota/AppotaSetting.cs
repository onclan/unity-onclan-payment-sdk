using UnityEngine;
using System.IO;
using System.Collections;
#if UNITY_EDITOR
using UnityEditor;

[InitializeOnLoad]
#endif

public class AppotaSetting : ScriptableObject
{

	const string appotaSettingsAssetName = "AppotaSettings";
	const string appotaSettingsPath = "Appota/Resources";
	const string appotaSettingsAssetExtension = ".asset";
	
	private static AppotaSetting instance;
	
	static AppotaSetting Instance
	{
		get
		{
			if (instance == null)
			{
				instance = Resources.Load(appotaSettingsAssetName) as AppotaSetting;
				if (instance == null)
				{
					// If not found, autocreate the asset object.
					instance = CreateInstance<AppotaSetting>();
					#if UNITY_EDITOR
					string properPath = Path.Combine(Application.dataPath, appotaSettingsPath);
					if (!Directory.Exists(properPath))
					{
						AssetDatabase.CreateFolder("Assets/Appota", "Resources");
					}
					
					string fullPath = Path.Combine(Path.Combine("Assets", appotaSettingsPath),
					                               appotaSettingsAssetName + appotaSettingsAssetExtension
					                               );
					AssetDatabase.CreateAsset(instance, fullPath);
					#endif
				}
			}
			return instance;
		}
	}

	#region App Settings
	[HideInInspector] [SerializeField]
	private string facebookAppID;
	[HideInInspector] [SerializeField]
	private string facebookAppSecretID;
	[HideInInspector] [SerializeField]
	private string twitterConsumerKey;
	[HideInInspector] [SerializeField]
	private string twitterConsumerSecret;
	[HideInInspector] [SerializeField]
	private string googleClientId;
	[HideInInspector] [SerializeField]
	private string googleClientSecretId;
    [HideInInspector] [SerializeField]
	private string clientID;
	[HideInInspector] [SerializeField]
	private string clientSecret;
	[HideInInspector] [SerializeField]
	private string inAppApiKey;
	[HideInInspector] [SerializeField]
	private string gameID;
	[HideInInspector] [SerializeField]
	private string leaderboardID;
	[HideInInspector] [SerializeField]
	private string sandboxApiKey;
	[HideInInspector] [SerializeField]
	private string paymentState;
	[HideInInspector] [SerializeField]
	private string noticeURL;
	[HideInInspector] [SerializeField]
	private string configURL;
	[HideInInspector] [SerializeField]
	private bool isUsingSandbox;

	public static string FacebookAppID
	{
		get { return Instance.facebookAppID; }
		set
		{
			if (Instance.facebookAppID != value)
			{
				Instance.facebookAppID = value;
				DirtyEditor();
			}
		}
	}

	public static string FacebookAppSecretID
	{
		get { return Instance.facebookAppSecretID; }
		set
		{
			if (Instance.facebookAppSecretID != value)
			{
				Instance.facebookAppSecretID = value;
                DirtyEditor();
            }
        }
    }

	public static string TwitterConsumerKey
	{
		get { return Instance.twitterConsumerKey; }
		set
		{
			if (Instance.twitterConsumerKey != value)
			{
				Instance.twitterConsumerKey = value;
				DirtyEditor();
			}
		}
	}

	public static string TwitterConsumerSecret
	{
		get { return Instance.twitterConsumerSecret; }
		set
		{
			if (Instance.twitterConsumerSecret != value)
			{
				Instance.twitterConsumerSecret = value;
				DirtyEditor();
			}
		}
	}

	public static string GoogleClientId
	{
		get { return Instance.googleClientId; }
		set
		{
			if (Instance.googleClientId != value)
			{
				Instance.googleClientId = value;
				DirtyEditor();
			}
		}
	}

	public static string GoogleClientSecretId
	{
		get { return Instance.googleClientSecretId; }
		set
		{
			if (Instance.googleClientSecretId != value)
			{
				Instance.googleClientSecretId = value;
                DirtyEditor();
            }
        }
    }

	public static string ClientID
	{
		get { return Instance.clientID; }
		set
		{
			if (Instance.clientID != value)
			{
				Instance.clientID = value;
				DirtyEditor();
			}
		}
	}

	public static string ClientSecret
	{
		get { return Instance.clientSecret; }
		set
		{
			if (Instance.clientSecret != value)
			{
				Instance.clientSecret = value;
                DirtyEditor();
            }
        }
    }

	public static string InAppApiKey
	{
		get { return Instance.inAppApiKey; }
		set
		{
			if (Instance.inAppApiKey != value)
			{
				Instance.inAppApiKey = value;
				DirtyEditor();
			}
		}
	}

	public static string GameID
	{
		get { return Instance.gameID; }
		set
		{
			if (Instance.gameID != value)
			{
				Instance.gameID = value;
				DirtyEditor();
			}
		}
	}

	public static string LeaderboardID
	{
		get { return Instance.leaderboardID; }
		set
		{
			if (Instance.leaderboardID != value)
			{
				Instance.leaderboardID = value;
				DirtyEditor();
			}
		}
	}

	public static string SandboxApiKey
	{
		get { return Instance.sandboxApiKey; }
		set
		{
			if (Instance.sandboxApiKey != value)
			{
				Instance.sandboxApiKey = value;
				DirtyEditor();
			}
		}
	}
	
	public static string PaymentState
	{
		get { return Instance.paymentState; }
		set
		{
			if (Instance.paymentState != value)
			{
				Instance.paymentState = value;
				DirtyEditor();
			}
		}
	}
	
	public static string NoticeURL
	{
		get { return Instance.noticeURL; }
		set
		{
			if (Instance.noticeURL != value)
			{
				Instance.noticeURL = value;
				DirtyEditor();
			}
		}
	}
	
	public static string ConfigURL
	{
		get { return Instance.configURL; }
		set
		{
			if (Instance.configURL != value)
            {
                Instance.configURL = value;
                DirtyEditor();
            }
        }
    }
    
    public static bool IsUsingSandbox
    {
        get { return Instance.isUsingSandbox; }
        set
        {
            if (Instance.isUsingSandbox != value)
            {
                Instance.isUsingSandbox = value;
                DirtyEditor();
            }
        }
    }
    
	
	private static void DirtyEditor()
	{
		#if UNITY_EDITOR
		EditorUtility.SetDirty(Instance);
		#endif
	}
	
	#endregion
}
