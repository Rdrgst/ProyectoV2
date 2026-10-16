#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX = 100;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
    int grupo;
};

struct Maestro {
    string nombre;
    string materia;
};

struct Grupo {
    string nombre;
    string carrera;
};

double calcularPromedio(float calif[3]) {
    double suma = 0;

    for (int i = 0; i < 3; i++) {
        suma += calif[i];
    }

    return suma / 3;
}

void registrarAlumnos(Alumno alumnos[], int &n) {
    int cantidad;

    cout << "\n¿Cuantos alumnos deseas registrar? ";
    cin >> cantidad;
    cin.ignore(1000, '\n');

    if (cantidad <= 0 || n + cantidad > MAX) {
        cout << "\nCantidad no valida o supera el limite.\n";
        return;
    }

    for (int i = n; i < n + cantidad; i++) {
        cout << "\nIngrese el nombre del alumno " << (i + 1) << ": ";
        getline(cin, alumnos[i].nombre);

        cout << "Ingrese la matricula del alumno " << (i + 1) << ": ";
        getline(cin, alumnos[i].matricula);

        cout << "Ingrese el grupo del alumno " << (i + 1) << ": ";
        cin >> alumnos[i].grupo;
        cin.ignore(1000, '\n');

        cout << "Ingrese las calificaciones del alumno " << (i + 1) << ":\n";

        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << (j + 1) << ": ";
            cin >> alumnos[i].calif[j];
        }

        cin.ignore(1000, '\n');
    }

    n += cantidad;

    cout << "\nAlumnos registrados correctamente.\n";
}

void registrarGrupos(Grupo grupos[], int &totalGrupos) {
    int cantidad;

    cout << "\n¿Cuantos grupos deseas registrar? ";
    cin >> cantidad;
    cin.ignore(1000, '\n');

    if (cantidad <= 0 || totalGrupos + cantidad > MAX) {
        cout << "\nCantidad no valida o supera el limite.\n";
        return;
    }

    for (int i = totalGrupos; i < totalGrupos + cantidad; i++) {
        cout << "\nIngrese el nombre del grupo " << (i + 1) << ": ";
        getline(cin, grupos[i].nombre);

        cout << "Ingrese la carrera del grupo " << (i + 1) << ": ";
        getline(cin, grupos[i].carrera);
    }

    totalGrupos += cantidad;

    cout << "\nGrupos registrados correctamente.\n";
}

void registrarMaestros(Maestro maestros[], int &totalMaestros) {
    int cantidad;

    cout << "\n¿Cuantos maestros deseas registrar? ";
    cin >> cantidad;
    cin.ignore(1000, '\n');

    if (cantidad <= 0 || totalMaestros + cantidad > MAX) {
        cout << "\nCantidad no valida o supera el limite.\n";
        return;
    }

    for (int i = totalMaestros; i < totalMaestros + cantidad; i++) {
        cout << "\nIngrese el nombre del maestro " << (i + 1) << ": ";
        getline(cin, maestros[i].nombre);

        cout << "Ingrese la materia del maestro " << (i + 1) << ": ";
        getline(cin, maestros[i].materia);
    }

    totalMaestros += cantidad;

    cout << "\nMaestros registrados correctamente.\n";
}

void mostrarAlumnos(Alumno alumnos[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << left;
    cout << setw(20) << "Nombre"
         << setw(15) << "Matricula"
         << setw(10) << "Grupo"
         << setw(12) << "Calif. 1"
         << setw(12) << "Calif. 2"
         << setw(12) << "Calif. 3"
         << setw(12) << "Promedio" << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << setw(20) << alumnos[i].nombre
             << setw(15) << alumnos[i].matricula
             << setw(10) << alumnos[i].grupo
             << setw(12) << alumnos[i].calif[0]
             << setw(12) << alumnos[i].calif[1]
             << setw(12) << alumnos[i].calif[2]
             << setw(12) << calcularPromedio(alumnos[i].calif) << endl;
    }
}

void mostrarGrupos(Grupo grupos[], int totalGrupos) {
    if (totalGrupos == 0) {
        cout << "\nNo hay grupos registrados.\n";
        return;
    }

    cout << left;
    cout << setw(20) << "Grupo"
         << setw(35) << "Carrera" << endl;

    for (int i = 0; i < totalGrupos; i++) {
        cout << setw(20) << grupos[i].nombre
             << setw(35) << grupos[i].carrera << endl;
    }
}

void mostrarMaestros(Maestro maestros[], int totalMaestros) {
    if (totalMaestros == 0) {
        cout << "\nNo hay maestros registrados.\n";
        return;
    }

    cout << left;
    cout << setw(25) << "Nombre"
         << setw(30) << "Materia" << endl;

    for (int i = 0; i < totalMaestros; i++) {
        cout << setw(25) << maestros[i].nombre
             << setw(30) << maestros[i].materia << endl;
    }
}

void promedioAlumnos(Alumno alumnos[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << "\n===== PROMEDIO DE CADA ALUMNO =====\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << alumnos[i].nombre
             << " - Promedio: "
             << calcularPromedio(alumnos[i].calif) << endl;
    }
}

void mejorPromedioPorGrupo(Alumno alumnos[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << "\n===== MEJOR PROMEDIO POR GRUPO =====\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        bool grupoYaRevisado = false;

        for (int j = 0; j < i; j++) {
            if (alumnos[i].grupo == alumnos[j].grupo) {
                grupoYaRevisado = true;
                break;
            }
        }

        if (grupoYaRevisado) {
            continue;
        }

        int grupoActual = alumnos[i].grupo;
        double mejorPromedio = calcularPromedio(alumnos[i].calif);
        string mejorAlumno = alumnos[i].nombre;

        for (int j = i + 1; j < n; j++) {
            if (alumnos[j].grupo == grupoActual) {
                double promedioActual = calcularPromedio(alumnos[j].calif);

                if (promedioActual > mejorPromedio) {
                    mejorPromedio = promedioActual;
                    mejorAlumno = alumnos[j].nombre;
                }
            }
        }

        cout << "Grupo " << grupoActual
             << ": " << mejorAlumno
             << " con promedio " << mejorPromedio << endl;
    }
}

void alumnosPorCarrera(Alumno alumnos[], int n, Grupo grupos[], int totalGrupos) {
    if (totalGrupos == 0) {
        cout << "\nNo hay grupos registrados.\n";
        return;
    }

    cout << "\n===== ALUMNOS POR CARRERA =====\n";

    for (int i = 0; i < totalGrupos; i++) {
        int contador = 0;

        for (int j = 0; j < n; j++) {
            if (alumnos[j].grupo == i + 1) {
                contador++;
            }
        }

        cout << grupos[i].carrera
             << ": " << contador << " alumno(s)\n";
    }
}

void mostrarReportes(Alumno alumnos[], int &n, Grupo grupos[], int &totalGrupos) {
    int opcionReporte;

    do {
        cout << "\n===== REPORTES =====\n";
        cout << "1. Promedio de cada alumno\n";
        cout << "2. Alumno con mejor promedio por grupo\n";
        cout << "3. Cantidad de alumnos por carrera\n";
        cout << "4. Volver al menu principal\n";
        cout << "Selecciona una opcion: ";
        cin >> opcionReporte;
        cin.ignore(1000, '\n');

        switch (opcionReporte) {
            case 1:
                promedioAlumnos(alumnos, n);
                break;

            case 2:
                mejorPromedioPorGrupo(alumnos, n);
                break;

            case 3:
                alumnosPorCarrera(alumnos, n, grupos, totalGrupos);
                break;

            case 4:
                cout << "\nVolviendo al menu principal...\n";
                break;

            default:
                cout << "\nOpcion no valida.\n";
        }

    } while (opcionReporte != 4);
}

int main() {
    Alumno alumnos[MAX];
    Maestro maestros[MAX];
    Grupo grupos[MAX];

    int n = 0;
    int totalMaestros = 0;
    int totalGrupos = 0;

    int opcion;

    cout << "===== PROYECTO V2 =====\n";

    do {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Registrar alumnos\n";
        cout << "2. Registrar grupos y carreras\n";
        cout << "3. Registrar maestros\n";
        cout << "4. Mostrar alumnos\n";
        cout << "5. Mostrar grupos\n";
        cout << "6. Mostrar maestros\n";
        cout << "7. Mostrar reportes\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        
    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = 0;
        } else {
            cin.ignore(1000, '\n');
        }

        switch (opcion) {
            case 1:
                registrarAlumnos(alumnos, n);
                break;

            case 2:
                registrarGrupos(grupos, totalGrupos);
                break;

            case 3:
                registrarMaestros(maestros, totalMaestros);
                break;

            case 4:
                mostrarAlumnos(alumnos, n);
                break;

            case 5:
                mostrarGrupos(grupos, totalGrupos);
                break;

            case 6:
                mostrarMaestros(maestros, totalMaestros);
                break;

            case 7:
                mostrarReportes(alumnos, n, grupos, totalGrupos);
                break;

            case 8:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion no valida. Intenta de nuevo.\n";
        }

    } while (opcion != 8);

    return 0;
}