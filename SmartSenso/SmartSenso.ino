#include <WiFi.h>
#include <FirebaseESP32.h>
#include <DHT.h>

// Cấu hình WiFi
#define WIFI_SSID "Tien"    
#define WIFI_PASS "13456789"

// Cấu hình Firebase
#define FIREBASE_HOST "duan-iot-87801-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "aDuNgczI7Yttn9VVz4u6yd67zjwPD3Jl8rZt7Dn2"

// Cấu hình cảm biến
#define DHTPIN 4       // GPIO4 kết nối DHT22
#define DHTTYPE DHT22
#define LED_PIN LED_BUILTIN // Sử dụng LED_BUILTIN (GPIO2)

DHT dht(DHTPIN, DHTTYPE);

// Khai báo đối tượng Firebase
FirebaseData fbData;
FirebaseConfig config;
FirebaseAuth auth;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  dht.begin();

  // Kết nối WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");

  // Cấu hình Firebase
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Kiểm tra kết nối Firebase
  if (Firebase.setString(fbData, "/test/connection", "ok")) {
    Serial.println("Connected to Firebase successfully!");
  } else {
    Serial.println("Failed to connect to Firebase: " + fbData.errorReason());
  }
}

void loop() {
  // Đọc dữ liệu từ DHT22
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  if (!isnan(temp) && !isnan(humi)) {
    // Gửi dữ liệu lên Firebase theo cấu trúc mới
    if (Firebase.setFloat(fbData, "/temperature", temp)) {
      Serial.printf("Temperature: %.2f°C sent to Firebase\n", temp);
    } else {
      Serial.println("Failed to send temperature: " + fbData.errorReason());
    }

    if (Firebase.setFloat(fbData, "/humidity", humi)) {
      Serial.printf("Humidity: %.2f%% sent to Firebase\n", humi);
    } else {
      Serial.println("Failed to send humidity: " + fbData.errorReason());
    }
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  // Nhận lệnh điều khiển LED từ Firebase (kiểu string "true"/"false")
  if (Firebase.getString(fbData, "/control/led")) {
    String ledState = fbData.stringData();
    bool ledOn = (ledState == "true");
    digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
    Serial.println("LED state: " + ledState);
  } else {
    Serial.println("Failed to get LED state: " + fbData.errorReason());
  }

  delay(2000); // Chờ 2 giây
}