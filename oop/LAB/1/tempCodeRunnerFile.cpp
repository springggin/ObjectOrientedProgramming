string filename;
    while (true) {
        cout << "Enter filename: ";
        cin >> filename;

        ifstream ifs(filename);

        if (!ifs) {
            cerr << "Failed to open the file. Please try again.\n";
        } else {
            cout << "File opened successfully!\n";
            // Task 9  Looping, reading file word by "word".
            string something;
            while (ifs >> something) {
              cout << something << endl;
            }

            ifs.close();  
            exit(1); 
        }
    }