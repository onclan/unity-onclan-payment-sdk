OnClanPaymentSDK Unity 
=========

Other Languages: [English](README.md)

**Các bước tích hợp OnClanPaymentSDK**

  - Import SDK vào project
  - Cấu hình SDK
  - Sử dụng SDK

Import SDK
---
Hãy chắc chắn là bạn đã có bản UnityOnClanPaymentSDK.unitypackage mới nhất. Sau khi mở Unity, để import package vào project, bạn click chuột phải trong Tab Project và làm theo hướng dẫn bên dưới.

![](docs/vn/Appota_Import.png) </br>


Bức ảnh cuối cùng hiển thị cấu trúc thư mục của OnClanPayment SDK. Bạn đã import thành công.

####iOS platform: 
Để có thể sử dụng SDK cho nền tảng iOS, bạn cần đặt toàn bộ frameworks cần thiết vào folder: Assets/Editor/XUPorter/Mods/iOS/Appota/ 

*Danh sách các frameworks*:

Trong folder Frameworks/
> FacebookSDK.framework
>
> GoogleOpenSource.framework
>
> GooglePlus.bundle	
>
> GooglePlus.framework
>
> OnClanBundle.bundle
>
> OnClanSDK.framework
>
> AppotaBundle.bundle
>
> AppotaSDK.framework

Cấu hình SDK
---
**Cấu hình Appota Setting**: Để sử dụng các chức năng của OnClanPayment SDK trước tiên cần vào menu Appota/Appota Setting để cài đặt các cấu hình ID

![](docs/vn/OnClan_Config_1.png) </br>

Cửa sổ Setting được hiện ra, ta cần điền đầy đủ thông tin cấu hình vào từng mục

![](docs/vn/OnCaln_Config_2.png) </br>

Cấu hình được phân chia làm 3 mục riêng biệt:

#### OnClan Settings

- **Game ID (optional)**: id tương ứng với game của nhà phát triển, liên hệ với Appota Game Supporter để nhận key.
- **Api Key**: liên hệ với Appota Game Supporter để nhận được key.
- **SandboxKey (optional)**: được cấp khi đăng kí ứng dụng trên trang developer của Appota.
- **Client ID**: Cấu hình trên dev.appota.com (dùng SANDBOX_CLIENT_ID trong chế độ sandbox).
- **Client Secret**: Cấu hình trên dev.appota.com
- **Leaderboard ID**: liên hệ với Appota Game Supporter để nhận key.

#### Social Settings
- **Facebook ID**: nhận Facebook ID từ việc đăng ký tạo ứng dụng trên trang https://developers.facebook.com/ (liên hệ với Appota Game team để tạo ứng dụng Facebook hoặc bạn có thể tự tạo ứng dụng cho riêng mình theo hướng dẫn của trang developer). 

> ![](docs/vn/OnClan_Facebook_AppID.png) </br>
>
> **Lưu ý:** Cấu hình BundleID(iOS) hay Package Name(Android) được khai báo trên trang Developer phải trùng khớp với Bundle Indentifier trong project Unity.
>
> ![](docs/vn/OnClan_Facebook_Compare_Bundle.png) </br>

- **Twitter Key**: nhận được khi đăng ký tạo ứng dụng trên trang https://dev.twitter.com/
- **Twitter Secret**: nhận được khi đăng ký tạo ứng dụng trên trang https://dev.twitter.com/

> ![](docs/vn/OnClan_Twitter_Key.png) </br>
> 
> Để có thể đăng nhập được Twitter, cần cấu hình thêm mục Callback URL
>
> ![](docs/vn/OnClan_Twitter_Detail.png) </br>

- **Google Client ID**: nhận Google Client ID từ việc đăng ký tạo ứng dụng trên trang Developer của Google theo hướng dẫn https://developers.google.com/+/mobile/ios/getting-started (liên hệ với Appota Game team để tạo ứng dụng hoặc bạn có thể tự tạo ứng dụng của riêng mình) 

> ![](docs/vn/OnClan_Google_Client_Id.png) </br>
>
> **Lưu ý:** Cấu hình BundleID(iOS) hay Package Name(Android) được khai báo trên trang Developer phải trùng khớp với Bundle Indentifier trong project Unity.
>
> ![](docs/vn/OnClan_Google_Compare_Bundle.png) </br>

#### Payment Settings

- **PaymentState (optional)**: YOUR_PAYMENT_STATE
- **ConfigUrl**: URL tới file config JSON
- **NoticeURL**: URL nhận thông báo từ Appota khi có giao dịch phát sinh.

Chọn **Update Settings** sau khi đã hoàn thành các thông số ID.

Sử dụng SDK
---

####Khởi tạo SDK
Trước khi có thể sử dụng các chức năng của SDK, cần gọi hàm khởi tạo để cấu hình ứng dụng:

```c#
public void Init();
```
*Cách sử dụng*: Gọi hàm này khi game bắt đầu được khởi tạo, nên đặt trong phương thức Override `Start()` hoặc `Awake()` của Unity và chỉ nên gọi một lần duy nhất trong game.
```c#
AppotaSDKHandler.Instance.Init();
```
####Payment Function
Sử dụng các phương thức của class AppotaSDKHandler để thực hiện các chức năng thanh toán
```c#
void ShowLoginView(): phương thức hiện form Login.
void SetAutoShowLogin(bool autoShowLogin): cài đặt chế độ tự động hiện form Login.
bool IsUserLogin(): trả về true nếu như người dùng đã login.
void Logout(): đăng xuất khỏi ứng dụng.
void SwitchAccount(): đăng nhập với tài khoản khác.
void MakePayment(): show form giao dịch thanh toán.
void ShowUserInfo(): hiển thị thông tin User.
void SetState(string paymentState): cài đặt trạng thái thanh toán.
```
*iOS Platform* có sự khác biệt với các chức năng:
```c#
void ShowPaymentButton(): show button truy cập nhanh vào form thanh toán.
void HidePaymentButton(): hide button truy cập nhanh vào form thanh toán.
void SetDelegate(): Cài đặt Delegate để có thể sử dụng được callback (đã được cài đặt mặc định trong Init(), nếu như không cần thiết, developer có thể comment lại dòng lệnh này)
```

####OnClan Function:

#####Hiện Leaderboard
Hàm hiển thị bảng xếp hạng thành tích (Leaderboard)

```c#
public void ShowLeaderBoard();
```

*Cách sử dụng*: Gọi hàm này khi nhà phát triển cần hiển thị bảng xếp
hạng thành tích trong game.

```c#
OnClanSDKHandler.Instance.ShowLeaderBoard();
```

#####Post Score 
Submit điểm lên Leaderboard.

```c#
public void PostScore(int score);
```
*Cách sử dụng*: Sau khi hoàn thành màn chơi, gọi hàm này để submit số điểm của người chơi lên. Server sẽ kiểm tra, nếu cao hơn điểm cũ sẽ thay thế bằng điểm hiện tại..

```c#
OnClanSDKHandler.Instance.PostScore(score);
```

####Callback: 
Nhận kết quả trả về từ OnClanPayment SDK và xử lý bằng cách cài đặt phần xử lý kết quả trong thân các hàm trong scripts <code>OnClanSDKReceiver.cs</code>.
```c#
// OnClanSDKReceiver.cs 
public void OnLoginSuccess(string appotaSession)
{
    // @appotaSession trả về là access_token của User
	// Cài đặt phần xử lý
}

public void OnLogoutSuccess()
{ 
	// Cài đặt phần xử lý
}

void OnSwitchAccountSuccess(string appotaSession)
{
    // @appotaSession trả về là access_token của User
	// Cài đặt phần xử lý
}
```

Scripts <code>AppotaSDKReceiver.cs</code>
```c#
public void OnPaymentSuccess(string transactionResult)
{
    // Cài đặt phần xử lý
}
```
- <code>@transactionResult</code>: trả về theo định dạng: https://github.com/appota/ios-game-sdk/blob/master/payment_format

####Cài đặt Icon Game (Android platform only)

Đối với Android platform, khi nhà phát triển sử dụng thư viện của bên thứ 3, Unity sẽ mặc định lấy icon Android thay thế cho Icon của game. Để tránh điều này, bạn đặt icons game vào trong folder Assets/Plugins/Android/res/drawable-xx 

![](docs/vn/OnClan_Icon_Settup.png) </br>

Mỗi folder *drawable* tương ứng với mỗi kích thước, độ phân giải của màn hình. Do vậy cần đặt các icon tương ứng vào các folder. Để biết thêm chi tiết về *drawable* tham khảo: 
http://developer.android.com/guide/practices/screens_support.html#overview
