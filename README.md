# Prototype-Charging-Station-Baterai-Kendaraan-Listrik-berbasis-Blynk
Proyek ini dirancang untuk mengisi baterai kendaraan listrik pada stasiun pengisian. Setelah baterai terisi penuh, relay akan bekerja memutus arus, dan informasi konsumsi daya yang harus dibayar oleh pelanggan akan ditampilkan. Pengukuran daya menggunakan sensor PZEM-004T, sedangkan modul TP4056 bertanggung jawab atas pengisian baterai 18650.

Komponen Utama:

Sensor PZEM-004T: Mengukur parameter daya seperti tegangan, arus, daya, dan energi.
Modul TP4056: Mengisi daya baterai 18650.
Mikrokontroler Wemos: Mengelola pengisian, relay, dan koneksi Blynk.
Relay: Mengontrol aliran daya saat baterai terisi penuh.
Layar LCD 16x2: Menampilkan parameter pengisian secara langsung.

Cara Penggunaan:

1. Sambungkan sensor PZEM-004T, modul TP4056, mikrokontroler Wemos, relay, dan layar LCD sesuai dengan petunjuk yang diberikan.
2. Konfigurasi kode sumber untuk mengendalikan pengisian, relay, dan komunikasi dengan Blynk.
3. Buat proyek di platform Blynk untuk memonitor dan mengontrol stasiun pengisian.
4. Jalankan program pada mikrokontroler Wemos. Data pengisian akan ditampilkan pada layar LCD dan dikirim ke platform Blynk.
5. Akses aplikasi Blynk untuk memantau dan mengontrol pengisian kendaraan listrik.
