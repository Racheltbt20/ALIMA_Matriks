#include <iostream>
using namespace std;

int main() {
    // start deklarasi variabel
    double matriks1[2][2] = {0}, matriks2[2][2] = {0}, invers[2][2] = {0}, hasil[2][2] = {0}, det;
    int i, j, k, opsi, pilmatriks;
    // end deklarasi variabel

    // start input value matriks
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << "Masukkan Matriks 1 ordo [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriks1[i][j];
        }
    }
    cout << "\n";
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << "Masukkan Matriks 2 ordo [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriks2[i][j];
        }
    }
    cout << "\n";
    // end input value matriks

    // start pilih opsi matriks
    cout << "Pilihlah perhitungan matriks 2x2 yang diinginkan\n";
    cout << "1. Penjumlahan\n"; 
    cout << "2. Pengurangan\n"; 
    cout << "3. Perkalian\n"; 
    cout << "4. Determinan Matriks\n"; 
    cout << "5. Invers Matriks\n"; 
    cout << "Masukkan pilihan (contoh: 1): ";
    cin >> opsi;
    // end pilih opsi matriks

    cout << "\n";

    // start tampilkan value matriks
    if(opsi >= 1 && opsi <=3) {
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
        cout << "\n\n";
    } else if(opsi == 4 || opsi == 5) {
        cout << "Pilih matriks yang diinginkan (1 atau 2): ";
        cin >> pilmatriks;
        cout << "\n";

        if(pilmatriks == 1) {
            cout << "Matriks = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t  ";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                        cout << matriks1[i][j] << " ";
                }
                cout << "|";
            }
            cout << "\n\n";
        } else if(pilmatriks == 2) {
            cout << "Matriks = ";
            for(i = 0; i < 2; i++) {
                if(i >= 1) {
                    cout << "\n\t  ";
                }
                cout << "| ";
                for(j = 0; j < 2; j++) {
                        cout << matriks2[i][j] << " ";
                }
                cout << "|";
            }
            cout << "\n\n";
        }
    }
    // end tampilkan value matriks

    // start proses perhitunan
    switch (opsi) {
        case 1: // penjumlahan
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    hasil[i][j] = matriks1[i][j] + matriks2[i][j];
                }
            }

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
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    hasil[i][j] = matriks1[i][j] - matriks2[i][j];
                }
            }

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
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    for(k = 0; k < 2; k++) {
                        hasil[i][j] += matriks1[i][k] * matriks2[k][j];
                    }
                }
            }

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
            if(pilmatriks == 1) {
                det = matriks1[0][0] * matriks1[1][1] - matriks1[0][1] * matriks1[1][0];
                cout << "Determinan = " << det;
            } else if(pilmatriks == 2) {
                det = matriks2[0][0] * matriks2[1][1] - matriks2[0][1] * matriks2[1][0];
                cout << "Determinan = " << det;
            } else {
                cout << "Masukkan pilihan matriks 1 atau 2!\n";
            }
            break;

        case 5: // invers
            if(pilmatriks == 1) {
                det = matriks1[0][0] * matriks1[1][1] - matriks1[0][1] * matriks1[1][0];
                if (det == 0) {
                    cout << "Matriks tidak memiliki invers karena determinan = 0.\n";
                    break;
                }
                invers[0][0] = matriks1[1][1];
                invers[0][1] = -matriks1[0][1];
                invers[1][0] = -matriks1[1][0];
                invers[1][1] = matriks1[0][0];
            } else if(pilmatriks == 2) {
                det = matriks2[0][0] * matriks2[1][1] - matriks2[0][1] * matriks2[1][0];
                if (det == 0) {
                    cout << "Matriks tidak memiliki invers karena determinan = 0.\n";
                    break;
                }
                invers[0][0] = matriks2[1][1];
                invers[0][1] = matriks2[0][1] * -1;
                invers[1][0] = matriks2[1][0] * -1;
                invers[1][1] = matriks2[0][0];
            } else {
                cout << "Masukkan pilihan matriks 1 atau 2!\n";
                break;
            }

            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    hasil[i][j] = (1.0 / det) * invers[i][j];
                }
            }

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
    // end proses perhitungan
    
    return 0;
}