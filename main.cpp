#include <iostream>
using namespace std;

int main() {
    //deklarasi variabel
    double matriks1[2][2], matriks2[2][2], hasil[2][2] = {0}, det;
    int i, j, k, pilih;

    // menentukan perhitungan matriks yang diinginkan
    cout << "Pilihlah perhitungan matriks 2x2 yang diinginkan\n";
    cout << "1. Penjumlahan\n"; 
    cout << "2. Pengurangan\n"; 
    cout << "3. Perkalian\n"; 
    cout << "4. Determinan Matriks\n"; 
    cout << "5. Invers Matriks\n"; 
    cout << "Masukkan pilihan (contoh: 1): ";
    cin >> pilih;

    cout << "\n";

    // jika memilih penjumlahan, pengurangan, perkalian
    if(pilih >=1 && pilih <= 3) {
        // input value matriks
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                cout << "Masukkan Matriks 1 ordo [" << i+1 << "][" << j+1 << "]: ";
                cin >> matriks1[i][j];
            }
        }
        cout << endl;
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                cout << "Masukkan Matriks 2 ordo [" << i+1 << "][" << j+1 << "]: ";
                cin >> matriks2[i][j];
            }
        }

        // output matriks
        cout << "Matriks 1 = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t    ";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << matriks1[i][j] << " ";
            }
            cout << "|";
        }
        cout << "\n\n";
        cout << "Matriks 2 = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t    ";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << matriks2[i][j] << " ";
            }
            cout << "|";
        }
    } else if(pilih == 4 || pilih == 5) { // jika memilih determinan, invers
        // input value matriks
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                cout << "Masukkan Matriks 1 ordo [" << i+1 << "][" << j+1 << "]: ";
                cin >> matriks1[i][j];
            }
        }

        // output matriks
        cout << "Matriks 1 = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t    ";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << matriks1[i][j] << " ";
            }
            cout << "|";
        }
    }

    cout << "\n\n";

    // proses menghitung sesuai perhitungan yang diinginkan
    switch (pilih) {
        case 1: // penjumlahan
            // hitung hasil
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    hasil[i][j] = matriks1[i][j] + matriks2[i][j];
                }
            }

            // output
            cout << "Hasil = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << hasil[i][j] << " ";
                }
                cout << "|";
            }
            break;
        case 2: // pengurangan
            // hitung hasil
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    hasil[i][j] = matriks1[i][j] - matriks2[i][j];
                }
            }

            // output
            cout << "Hasil = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << hasil[i][j] << " ";
                }
                cout << "|";
            }
            break;
        case 3: // perkalian
            // hitung hasil
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    for(k = 0; k < 2; k++) {
                        hasil[i][j] += matriks1[i][k] * matriks2[k][j];
                    }
                }
            }

            // output
            cout << "Hasil = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << hasil[i][j] << " ";
                }
                cout << "|";
            }
            break;
        case 4: // determinan
            // hitung hasil
            det = matriks1[0][0] * matriks1[1][1] - matriks1[0][1] * matriks1[1][0];
            
            // output
            cout << "Determinan = " << det;
            break;
            case 5: // invers
            // hitung determinan
            det = matriks1[0][0] * matriks1[1][1] - matriks1[0][1] * matriks1[1][0]; 

            // ubah matriks
            matriks2[0][0] = matriks1[1][1];
            matriks2[0][1] = matriks1[0][1] * -1;
            matriks2[1][0] = matriks1[1][0] * -1;
            matriks2[1][1] = matriks1[0][0];

            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    hasil[i][j] = 1 / det * matriks2[i][j];
                }
            }

            // output
            cout << "Hasil = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                    cout << hasil[i][j] << " ";
                }
                cout << "|";
            }
            break;
        default:
            cout << "Harap masukkan angka 1 - 5!";
            break;
    }
    
    return 0;
}