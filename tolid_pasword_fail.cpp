#include <iostream>//ktabkh onh vorodi as kar bar
#include <fstream>//ktabkh onh kar ba fail 
using namespace std;//fazayh nam barayh kotah kardan nam 
int main() {

    int seed = 12345u; //mkdar avaliah tolid adad tsadofi
    char again; //porsidan adamh midh
    do {
        ////////////////////////////////////////////////////////////////////////////////////
        //graftan tol reshtah	
        int length;
        cout << "\a======Sakhte Password Jadid======\n\n";
        cout << "Tool password ra vared kon (az 1 ta 49)->:\t ";
        cin >> length;
        ///////////////////////////////////////////////////////////////////////////////////
        //barasy tol resh th
        if (length < 1 || length > 49) {
            cout << "? Tool ghabul nist. Maksimum 49 ta karakter.\n";
            continue; // bar gard aval halgh vamgdar bger
        }
        ////////////////////////////////////////////////////////////////////////////////////
        //karak ter hay mojaz
        const char* all = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?";
        int allLength = 0;
        while (all[allLength] != '\0') allLength++;
        char password[50];
        ////////////////////////////////////////////////////////////////////////////////////////////
        //tolid_ya_sahkt_adad_tasadofi
        for (int i = 0; i < length; i++) {
            seed = (1103515245u * seed + 12345u) & 0x7fffffffu;
            int randomIndex = seed % allLength;
            password[i] = all[randomIndex];
        }
        password[length] = '\0'; // payan rsh tah
        cout << "Password sakhte shod: " << password << endl;
        /////////////////////////////////////////////////////////////////////////////////////////////
        // sakht va zakerh fail
        ofstream file("passwords.txt", ios::app);
        if (file) {
            file << password << endl;
            file.close();
            cout << "?? Password dar file (passwords.txt) zakhire shod.\n";
        }
        else {
            cout << "?? Error: nemitavan file ra baz kard.\n";
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        // soal barayadamh
        cout << "Mikhahi dobare password besazi? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    ////////////////////////////////////////////////////////////////////////////////////////////
    //again==n
    cout << "\nKhoroj az barname...\n";
    return 0;
}
