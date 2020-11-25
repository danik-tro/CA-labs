#include <iostream>
#include <cstdio>
#include <cstring>
#include <getopt.h>
#include <cstdlib>

using namespace std;



class Activator {
public:
	Activator(string name_="") {
		cout << "Activator's work has started " << name_ << '\n';
		SomeAction();
	}

	~Activator() {
		cout << "Activator's work has finished.\n";
	}

	void SomeAction() {
		for (int i =0; i < 100; i += 25)
			cout << "Activator is working... " << i << "%\n";
	}
};


int main(int argc, char *argv[]) {

    const char *s_par = "ha:vl:";

    const struct option l_par[] = {
            {"help",    no_argument,       NULL, 'h'},
            {"activator",    optional_argument, NULL, 'a'},
            {"version", no_argument,       NULL, 'v'},
            {"list",    required_argument, NULL, 'l'},
            {NULL, 0,                      NULL, 0}
    };

    int rez;
    double size = 1.0;
    bool h_level = false, a_level = false, v_level = false, l_level = false;
    int option_index;

    while ((rez = getopt_long(argc, argv, s_par,
                              l_par, &option_index)) != -1) {

        switch (rez) {
            case 'h': {
                if (!h_level) {
                    cout << "List of arguments:\n"
                                "-a[name] or --activator=[name] - with option to set name\n"
                                "-h or --help - reuturn help\n"
                                "-v or --version - return version\n"
                                "-l[<val1>,...] or --list=[<num1>,...] - input list\n";
                    h_level = true;
                }
                break;
            }
            case 'a': {
                if (!a_level) {
                    if (optarg != NULL) {
                        Activator(optarg);
                    } else {
                        cout << "Activator don't work.\n";
                    }
                    a_level = true;
                }
                break;
            }
            case 'v': {
                if (!v_level) {
                    cout << "** Version: Latest **\n";
                    v_level = true;
                }
                break;
            }
            case 'l': {
                if (!l_level) {
                    cout << "**Printed list: { ";
                    char *elem = strtok(optarg, ",");
                    while (elem != NULL) {
                        printf("%s ", elem);
                        elem = strtok(NULL, ",");
                    }
                    cout << "} **\n";
                    l_level = true;
                }
                break;
            }
            case '?':
            default: {
                cout << "Type -h or --help\n";
                break;
            }
        }
    }
    return 0;
}