
# 📱 Ứng dụng Giám Sát & Điều Khiển IoT

## 🎥 Video Demo

👉 [Xem video demo tại đây](./VideoDemo/demo.mp4)

---

## 👨‍💻 Nhóm thực hiện

- **Trần Văn Đạt**
- **Bùi Thị Giang**
- **Nguyễn Trung Sơn**

---

## 📌 Tính năng chính

- Giám sát **nhiệt độ** và **độ ẩm** từ cảm biến.
- Điều khiển **bật/tắt LED** thông qua app.
- Lưu và hiển thị dữ liệu thời gian thực lên **Firebase Realtime Database**.
- Ứng dụng Android giao diện trực quan dễ sử dụng.

---

## 📸 Hình ảnh minh họa

### 🔥 Ảnh Firebase
| Dữ liệu Firebase | Cấu hình Rules |
|:----------------|:---------------|
| ![Firebase Data](./Image/Firebase_Data.png) | ![Firebase Rules](./Image/firebase_rules.png) |

---

### 💻 Ảnh Code
| Code 1 | Code 2 | Code 3 |
|:-------|:-------|:-------|
| ![Code 1](./Image/code1.png) | ![Code 2](./Image/code2.png) | ![Code 3](./Image/code3.png) |

---

### 📱 Ảnh Thiết kế App
| Thiết kế Blocks | Thiết kế UI |
|:----------------|:------------|
| ![Blocks](./Image/Blocks.png) | ![Designer](./Image/Designer.png) |

---

### 📱 Ảnh App thực tế
![App](./Image/app.jpg)

---

## ⚙️ Hướng dẫn cài đặt

### 🔧 Cài đặt Arduino IDE
- Tải và cài đặt Arduino IDE tại: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
- Thêm thư viện **Firebase ESP8266** và các thư viện cảm biến liên quan.

### 📥 Clone project từ GitHub

```bash
git clone https://github.com/trandat2004/IoTControlApp.git
```

### 📱 Import app vào MIT App Inventor hoặc tải file `.apk` tại thư mục chính.

---

## 📑 Thông tin dự án

Ứng dụng điều khiển và giám sát nhiệt độ, độ ẩm qua Internet sử dụng **Firebase** và **Arduino ESP8266**. Dữ liệu cập nhật thời gian thực và có thể điều khiển LED từ xa qua app Android.

---

## 📌 Thư mục dự án

```
├── Image/                # Chứa ảnh minh họa
├── SmartSenso/           # Mã nguồn Arduino
├── VideoDemo/            # Video demo
├── IoTControlApp.apk     # File cài đặt app Android
├── IoTControlApp_UI.aia  # File thiết kế App Inventor
└── README.md             # Tài liệu mô tả dự án
```
