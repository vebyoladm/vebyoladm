#include <iostream>
#include <windows.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void ShowResult();
void Login();
void DosenSystem();
void InsertData(string, string, string, float );
void MahasiswaSystem();
void ShowResult(string, string);

int main()
{
    Login();
}

void Login()
{
    string sebagai;
    string user, pass;
    cout << "===========================================================================" << endl;
    cout << "=================== SELAMAT DATANG DI PROGRAM ABSENSI =====================" << endl;
    cout << "================== MATAKULIAH ALGORITMA DAN PEMROGRAMAN ===================" << endl;
    cout << "===========================================================================" << endl;
    cout << "Masuk sebagai Dosen atau mahasiswa?" << endl << "[dosen|mahasiswa] ? : ";
    cin >> sebagai;

    if(sebagai == "dosen")
    {
        cout << "Username : "; cin >> user;
        cout << "Password : "; cin >> pass;
        if (user == "dosen" && pass == "12345")
        {
            DosenSystem();
        }
        else
        {
            cout << "Maaf username atau password anda salah!";
        }
    }
    else if (sebagai == "mahasiswa")
    {
        cout << "Username : "; cin >> user;
        cout << "Password : "; cin >> pass;
        if (user == "mhs2019" && pass == "12345")
        {
            MahasiswaSystem();
        }
        else
        {
            cout << "Maaf username atau password anda salah!";
        }
    }
}

void DosenSystem()
{
    string yt = "y";
    while (yt == "y" || yt == "Y")
    {
        system("cls");
        string nama, daftarHadirStr = "";
        string npm;
        string daftarHadir [14];
        cout << "===================================================" << endl;
        cout << "=========== INPUT DATA ABSENSI MAHASISWA ==========" << endl;
        cout << "===================================================" << endl;
        cin.get();
        cout << "Nama : "; getline(cin, nama);
        cout << "NPM  : "; cin >> npm;
        int i = 0, jumlahHadir = 0;
        cout << "Catatan* Input huruf [H] apabila hadir, input huruf [T] apabila tidak hadir!" << endl;
        while (i < 14)
        {
            cout << "Minggu ke - " << i + 1 << "    : "; cin >> daftarHadir[i];
            if (daftarHadir[i] == "h" || daftarHadir[i] == "H")
            {
                jumlahHadir++;
                daftarHadir[i] = "Hadir";
                daftarHadirStr += "'" + daftarHadir[i] + "', ";
            }
            else
            {
                daftarHadir[i] = "Tidak";
                daftarHadirStr += "'" + daftarHadir[i] + "', ";
            }
            i++;
        }
        float presentase = ((float) jumlahHadir / 14) * 100;
        cout << "Presentasi kehadiran mahasiswa " << nama << " adalah : " << fixed << setprecision(2) << presentase << "%." << endl;

        InsertData(npm, nama, daftarHadirStr, presentase);
        cout << "Mau masukkan data lagi? [y|t] : ";
        cin >> yt;
    }
}

void MahasiswaSystem()
{
    system("cls");
    string namaAnda, npmAnda;
    cin.get();
    cout << "Masukkan nama anda : "; getline(cin, namaAnda);
    cout << "Masukkan NPM anda  : "; cin >> npmAnda;
    system("cls");
    cout << "===================================================" << endl;
    cout << "======== DATA KEHADIRAN ABSENSI MAHASISWA =========" << endl;
    cout << "===================================================" << endl;

    ShowResult(namaAnda, npmAnda);

}

void ShowResult(string nama, string npm)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "mahasiswa", 0, NULL, 0);
    if (conn)
    {
        string query;
        query ="SELECT * FROM mahasiswatb WHERE nama = '" + nama + "' AND npm = '" + npm + "'";
        const char * c = query.c_str();
        int qstate = mysql_query(conn, c);

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {
                cout << "Nama : " << row[0] << endl
                     << "NPM  : " << row[1] << endl
                     << "Kehadiran anda selama 14 Minggu sebagai berikut :" << endl;

                for (int i = 0; i < 14; i++)
                {
                    cout << "Minggu ke - " << i + 1 << "   : " << row[i + 2] << endl;
                }
                cout << "Presentase kehadiran anda adalah : " << row[16] << "%" << endl;

                float hasil = atof(row[16]);
                if (hasil >= 50)
                {
                    cout << "Anda boleh mengikuti ujian!" << endl;
                }
                else
                {
                    cout << "Anda tidak diperkenankan mengikuti ujian!" << endl;
                }
            }
        }
        else
        {
            cout << "Nama atau NPM yang anda masukkan salah!" << endl;
        }
    }
}

void InsertData(string nama, string npm, string daftarHadir, float persen)
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "mahasiswa", 0, NULL, 0);

    int qstate = 0;
    int i = 0;

    stringstream ss;

    string syntax, daftarSyntax = "", persenSyntax = "";
    syntax = "INSERT INTO mahasiswatb VALUES ('" + npm + "', '" + nama + "', " + daftarHadir;
    ss << syntax << daftarSyntax << persen << ")";

    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0)
        cout << "Data sudah dimasukkan ke dalam Database!" << endl;
    else
        cout << "Data tidak berhasil dimasukkan ke dalam Database!" << endl;
}

void CheckConnection()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "mahasiswa", 0, NULL, 0);

    if (conn)
        cout << "Connected";
    else
        cout << "Not Connected";
}
