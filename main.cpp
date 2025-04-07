#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // start deklarasi variabel
    double matriks1[2][2] = {0}, matriks2[2][2] = {0}, invers[2][2] = {0}, hasil[2][2] = {0}, det;
    int i, j, k, opsi, pilmatriks;
    char ulang, pakaiInputSebelumnya;
    bool inputLama = false;
    // end deklarasi variabel

    cout << "\n===== Program Operasi Matriks 2x2 =====\n";

    do{
        // start input value matriks
        if(!inputLama) {
            cout << "\nMasukkan elemen matriks A: \n";
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    cout << "Baris " << i+1 << " Kolom " << j+1 << " = ";
                    cin >> matriks1[i][j];
                }
            }
            cout << "\nMasukkan elemen matriks B: \n";
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    cout << "Baris " << i+1 << " Kolom " << j+1 << " = ";
                    cin >> matriks2[i][j];
                }
            }
        }
        // end input value matriks

        // start pilih opsi matriks
        cout << "\nPilihlah operasi matriks 2x2 yang diinginkan\n";
        cout << "1. Penjumlahan\n"; 
        cout << "2. Pengurangan\n"; 
        cout << "3. Perkalian\n"; 
        cout << "4. Determinan Matriks\n"; 
        cout << "5. Invers Matriks\n"; 
        cout << "6. Transpose Matriks\n";
        cout << "Masukkan pilihan (contoh: 1): ";
        cin >> opsi;
        // end pilih opsi matriks

        // start validasi opsi
        if(cin.fail()) {
            cout << "\nInput harus berupa angka 1 - 6!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else { // end validasi opsi
            // start tampilkan elemen matriks
            if(opsi >= 1 && opsi <=3) {
                cout << "\nMatriks A = \n";
                for(i = 0; i < 2; i++) {
                    cout << "| ";
                    for(j = 0; j < 2; j++) {
                            cout << setw(6) << matriks1[i][j] << setw(6);
                    }
                    cout << "|\n";
                }

                cout << "\nMatriks B = \n";
                for(i = 0; i < 2; i++) {
                    cout << "| ";
                    for(j = 0; j < 2; j++) {
                            cout << setw(6) << matriks2[i][j] << setw(6);
                    }
                    cout << "|\n";
                }
            } else if(opsi >= 4 && opsi <= 6) {
                cout << "Pilih matriks yang diinginkan (1 atau 2): ";
                cin >> pilmatriks;

                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    if(pilmatriks == 1) {
                        cout << "\nMatriks = \n";
                        for(i = 0; i < 2; i++) {
                            cout << "| ";
                            for(j = 0; j < 2; j++) {
                                    cout << setw(6) << matriks1[i][j] << setw(6);
                            }
                            cout << "|\n";
                        }
                    } else if(pilmatriks == 2) {
                        cout << "\nMatriks = \n";
                        for(i = 0; i < 2; i++) {
                            cout << "| ";
                            for(j = 0; j < 2; j++) {
                                    cout << setw(6) << matriks2[i][j] << setw(6);
                            }
                            cout << "|\n";
                        }
                    }
                }
            }
            // end tampilkan elemen matriks
    
            // start operasi perhitungan
            switch (opsi) {
                case 1: // penjumlahan
                    for(i = 0; i < 2; i++) {
                        for(j = 0; j < 2; j++) {
                            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
                        }
                    }
    
                    cout << "\nHasil Penjumlahan Matriks = \n";
                    for(i = 0; i < 2; i++) {
                        cout << "| ";
                        for(j = 0; j < 2; j++) {
                                cout << setw(6) << hasil[i][j] << setw(6);
                        }
                        cout << "|\n";
                    }
                    break;
                case 2: // pengurangan
                    for(i = 0; i < 2; i++) {
                        for(j = 0; j < 2; j++) {
                            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
                        }
                    }
    
                    cout << "\nHasil Pengurangan Matriks = \n";
                    for(i = 0; i < 2; i++) {
                        cout << "| ";
                        for(j = 0; j < 2; j++) {
                                cout << setw(6) << hasil[i][j] << setw(6);
                        }
                        cout << "|\n";
                    }
                    break;
                case 3: // perkalian
                    for(i = 0; i < 2; i++) {
                        for(j = 0; j < 2; j++) {
                            hasil[i][j] = 0;
                        }
                    }
    
                    for(i = 0; i < 2; i++) {
                        for(j = 0; j < 2; j++) {
                            for(k = 0; k < 2; k++) {
                                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
                            }
                        }
                    }
    
                    cout << "\nHasil Perkalian Matriks = \n";
                    for(i = 0; i < 2; i++) {
                        cout << "| ";
                        for(j = 0; j < 2; j++) {
                                cout << setw(6) << hasil[i][j] << setw(6);
                        }
                        cout << "|\n";
                    }
                    break;
                case 4: // determinan
                    if(pilmatriks == 1) {
                        det = matriks1[0][0] * matriks1[1][1] - matriks1[0][1] * matriks1[1][0];
                        cout << "\nDeterminan Matriks = " << det << "\n";
                    } else if(pilmatriks == 2) {
                        det = matriks2[0][0] * matriks2[1][1] - matriks2[0][1] * matriks2[1][0];
                        cout << "\nDeterminan Matriks = " << det << "\n";
                    } else {
                        cout << "\nMasukkan pilihan matriks 1 atau 2!\n";
                    }
                    break;
                case 5: // invers
                    if(pilmatriks == 1) {
                        det = matriks1[0][0] * matriks1[1][1] - matriks1[0][1] * matriks1[1][0];
                        if (det == 0) {
                            cout << "\nMatriks tidak memiliki invers karena determinan = 0.\n";
                            break;
                        } else {
                            invers[0][0] = matriks1[1][1];
                            invers[0][1] = -matriks1[0][1];
                            invers[1][0] = -matriks1[1][0];
                            invers[1][1] = matriks1[0][0];
                        }
                    } else if(pilmatriks == 2) {
                        det = matriks2[0][0] * matriks2[1][1] - matriks2[0][1] * matriks2[1][0];
                        if (det == 0) {
                            cout << "\nMatriks tidak memiliki invers karena determinan = 0.\n";
                            break;
                        } else {
                            invers[0][0] = matriks2[1][1];
                            invers[0][1] = -matriks2[0][1];
                            invers[1][0] = -matriks2[1][0];
                            invers[1][1] = matriks2[0][0];
                        }
                    } else {
                        cout << "\nMasukkan pilihan matriks 1 atau 2!\n";
                        break;
                    }
    
                    for(i = 0; i < 2; i++) {
                        for(j = 0; j < 2; j++) {
                            hasil[i][j] = (1.0 / det) * invers[i][j];
                        }
                    }
    
                    cout << "\nInvers Matriks = \n";
                    for(i = 0; i < 2; i++) {
                        cout << "| ";
                        for(j = 0; j < 2; j++) {
                                cout << setw(6) << hasil[i][j] << setw(6);
                        }
                        cout << "|\n";
                    }
                    break;
                case 6:
                    if(pilmatriks == 1) {
                        for(i = 0; i < 2; i++) {
                            for(j = 0; j < 2; j++) {
                                hasil[j][i] = matriks1[i][j];
                            }
                        }
                    } else if(pilmatriks == 2) {
                        for(i = 0; i < 2; i++) {
                            for(j = 0; j < 2; j++) {
                                hasil[j][i] = matriks2[i][j];
                            }
                        }
                    } else {
                        cout << "\nMasukkan pilihan matriks 1 atau 2!\n";
                        break;
                    }

                    cout << "\nTranspose Matriks= \n";
                    for(i = 0; i < 2; i++) {
                        cout << "| ";
                        for(j = 0; j < 2; j++) {
                            cout << setw(6) << hasil[i][j] << setw(6);
                        }
                        cout << "|\n";
                    }
                    break;
                default:
                    cout << "\nHarap masukkan angka 1 - 5!\n";
                    break;
            }
            // end proses perhitungan
        }
        
        cout << "\nIngin melakukan operasi lagi? (y/n): ";
        cin >> ulang;

        if(ulang == 'y' || ulang == 'Y') {
            cout << "Gunakan matriks sebelumnya? (y/n): ";
            cin >> pakaiInputSebelumnya;  
            
            if(pakaiInputSebelumnya == 'y' || pakaiInputSebelumnya == 'Y') {
                inputLama = true;
            } else {
                inputLama = false;
            }
        }
    } while (ulang == 'y' || ulang == 'Y');
    
    return 0;
}