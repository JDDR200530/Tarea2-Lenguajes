#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Cuenta_Bancaria
{
private:
    int Numero_Cuenta;
    double Balance;
    vector<string> Historial_Transacciones;

public:
    // Constructor de la cuenta bancaria
    Cuenta_Bancaria(int Numero_Cuenta, double Balance) : Numero_Cuenta(Numero_Cuenta), Balance(Balance)
    {
        Historial_Transacciones.push_back("Cuenta creada con balance inicial de " + to_string(Balance));
    }

    // Función para obtener el número de cuenta
    int obtenerNumeroCuenta() const
    {
        return Numero_Cuenta;
    }

    // Función para realizar un depósito
    void Depositar(double Cantidad)
    {
        if (Cantidad <= 0)
        {
            throw invalid_argument("La cantidad del depósito debe ser mayor a 0");
        }
        Balance += Cantidad;
        Historial_Transacciones.push_back("Deposito de " + to_string(Cantidad));
    }

    // Función para realizar un retiro
    void Retirar(double Cantidad)
    {
        if (Cantidad <= 0)
        {
            throw invalid_argument("La cantidad a retirar debe ser mayor a 0");
        }
        if (Cantidad > Balance)
        {
            throw invalid_argument("Fondos insuficientes para realizar el retiro");
        }
        Balance -= Cantidad;
        Historial_Transacciones.push_back("Retiro de " + to_string(Cantidad));
    }

    // Función para obtener el balance
    double ObtenerBalance() const
    {
        return Balance;
    }

    // Función para mostrar el historial de transacciones
    void mostrarHistorial() const
    {
        cout << "\nHistorial de transacciones para la cuenta " << Numero_Cuenta << ":\n";
        for (const string &Transaccion : Historial_Transacciones)
        {
            cout << "- " << Transaccion << endl;
        }
    }
};

int main()
{
    vector<Cuenta_Bancaria> cuentas;
    int opcion;

    do
    {
        cout << "\nSistema Bancario\n";
        cout << "1. Crear Cuenta\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Ver Balance\n";
        cout << "5. Ver Historial\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        try
        {
            switch (opcion)
            {
            case 1:
            {
                int numeroCuenta;
                double balanceInicial;
                cout << "Ingrese el numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Ingrese el Balance Inicial: ";
                cin >> balanceInicial;
                cuentas.emplace_back(numeroCuenta, balanceInicial);
                cout << "Cuenta creada con exito.\n";
                break;
            }
            case 2:
            {
                int numeroCuenta;
                double cantidad;
                cout << "Ingrese el numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Ingrese la cantidad a depositar: ";
                cin >> cantidad;
                bool cuentaEncontrada = false;
                for (auto &cuenta : cuentas)
                {
                    if (cuenta.obtenerNumeroCuenta() == numeroCuenta)
                    {
                        cuenta.Depositar(cantidad);
                        cout << "Deposito realizado con exito.\n";
                        cuentaEncontrada = true;
                        break;
                    }
                }
                if (!cuentaEncontrada)
                {
                    cout << "Cuenta no encontrada.\n";
                }
                break;
            }
            case 3:
            {
                int numeroCuenta;
                double cantidad;
                cout << "Ingrese el numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cantidad;
                bool cuentaEncontrada = false;
                for (auto &cuenta : cuentas)
                {
                    if (cuenta.obtenerNumeroCuenta() == numeroCuenta)
                    {
                        cuenta.Retirar(cantidad);
                        cout << "Retiro realizado con exito.\n";
                        cuentaEncontrada = true;
                        break;
                    }
                }
                if (!cuentaEncontrada)
                {
                    cout << "Cuenta no encontrada.\n";
                }
                break;
            }
            case 4:
            {
                int numeroCuenta;
                cout << "Ingrese el numero de cuenta: ";
                cin >> numeroCuenta;
                bool cuentaEncontrada = false;
                for (const auto &cuenta : cuentas)
                {
                    if (cuenta.obtenerNumeroCuenta() == numeroCuenta)
                    {
                        cout << fixed << setprecision(2);
                        cout << "Balance de la cuenta " << numeroCuenta << ": " << cuenta.ObtenerBalance() << "\n";
                        cuentaEncontrada = true;
                        break;
                    }
                }
                if (!cuentaEncontrada)
                {
                    cout << "Cuenta no encontrada.\n";
                }
                break;
            }
            case 5:
            {
                int numeroCuenta;
                cout << "Ingrese el numero de cuenta: ";
                cin >> numeroCuenta;
                bool cuentaEncontrada = false;
                for (const auto &cuenta : cuentas)
                {
                    if (cuenta.obtenerNumeroCuenta() == numeroCuenta)
                    {
                        cuenta.mostrarHistorial();
                        cuentaEncontrada = true;
                        break;
                    }
                }
                if (!cuentaEncontrada)
                {
                    cout << "Cuenta no encontrada.\n";
                }
                break;
            }
            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    } while (opcion != 6);

    return 0;
}
