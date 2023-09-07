#include "mbed.h"
#include <iostream>
#include <vector>
#include <cstdlib> // Necesario para std::atoi

#define DEBOUNCE_DELAY 200ms

const int ROWS = 4;
const int COLS = 3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

const char NO_KEY = '\0';
char key;

DigitalIn rowPins[ROWS] = {PTC9, PTC8, PTA5, PTA4};
DigitalOut colPins[COLS] = {PTA12, PTD4, PTC0};

char readKeyPad() {
    // Loop through each column, set it as output, and scan rows
    for (int col = 0; col < COLS; col++) {
        colPins[col] = 0; // Set the column low

        for (int row = 0; row < ROWS; row++) {
            if (rowPins[row] == 0) { // Check if the key is pressed
                ThisThread::sleep_for(DEBOUNCE_DELAY); // Debounce Delay
                if (rowPins[row] == 0) {
                    colPins[col] = 1; // Release the current column
                    return keys[row][col]; // Return the pressed key
                }
            }
        }

        colPins[col] = 1; // Release the current column
    }

    return NO_KEY; // Return if no key is pressed
}

void uno(char key){
    double x1, y1, x2, y2;
    double m, b;
    bool flag = true;
    
    while(flag == true){

     cout << "Ingrese las coordenada en x del primer punto (X1): ";
     key = readKeyPad();
     while(key != '#'){
        x1 = key;
     }
     cout << "Ingrese las coordenada en y del primer punto (Y1): ";
     key = readKeyPad();
     while(key != '#'){
        y1 = key;
     }

    cout << "Ingrese las coordenada en x del segundo punto (X2): ";
    key = readKeyPad();
    while(key != '#'){
        x2 = key;
     }
     cout << "Ingrese las coordenada en y del segundo punto (Y2): ";
     key = readKeyPad();
     while(key != '#'){
        y2 = key;
        }       

    if(x1 == x2) {
         cout << "La pendiente es indeterminada (división por 0)." << std::endl;
    } else {
         m = (y2 - y1) / (x2 - x1);
         b = y1 - (m * x1);

        cout << "La pendiente de la recta es: " << m << std::endl;
        cout << "El intercepto con el eje y es: " << b << std::endl;
        }
        flag = false;
    }
}


int promedio(const std::vector<int>& temperaturas)
{
    int suma = 0;
    for (int elemento : temperaturas) {
        suma += elemento;
    }
    return suma / temperaturas.size();
}

int devEstandar(const std::vector<int>& temperaturas) {
                                                    
    int promedio_temperaturas = promedio(temperaturas);
    int sumaDiferenciasCuadradas = 0;
                                                                
    for (int elemento : temperaturas) {
        int diferencia = elemento - promedio_temperaturas;
        sumaDiferenciasCuadradas += diferencia * diferencia;
    }

    int desviacionEstandar = std::sqrt(static_cast<double>(sumaDiferenciasCuadradas) / temperaturas.size());
    return desviacionEstandar;                                                         
}


int dos(){
    std::cout>> "Ingrese la cantidad de temperaturas a registrar";
    string key = readKeyPad();
    int n = std::atoi(key);

    std::vector<int> temperaturas(n);

    std::cout>> "Ingrese las temperaturas separadas por el #";

    for(int elemento : temperaturas){
        while(key != '#'){
            key = readKeyPad();
            elemento += std::atoi(key);
        } 
    }
    
    int promedio_temperaturas = promedio(temperaturas);
    int desviacion_estandar = devEstandar(temperaturas);

    std::cout << "El promedio es " << promedio_temperaturas << " y la desviación estándar es " << desviacion_estandar << std::endl;

}

int hexaDeci(const std::string& nHex) {
    int nDeci = 0;
    int base = 16;
    
    for (int i = nHex.size() - 1, exp = 0; i >= 0; i--, exp++) {
        char digit = nHex[i];

        if (isdigit(digit)) {
            nDeci += (digit - '0') * pow(base, exp);
        } else if (isalpha(digit)) {
            // (A=10, B=11, ..., F=15)
            nDeci += (toupper(digit) - 'A' + 10) * pow(base, exp);
        } else {
            // Error 
            std::cout << "Caracter no valido en el numero hexadecimal: " << digit << std::endl;
            return -1;
        }
    }
    return nDeci;
}

void tres() {
    
    PwmOut red(LED1);
    PwmOut green(LED2);
    PwmOut blue(LED3);

    std::string hex;
    float pwmR = 0.0;
    float pwmG = 0.0;
    float pwmB = 0.0;

    std::cout << "Ingrese el código hexadecimal: ";
    std::cin >> hex;

    if (hex.length() != 6) {
        std::cout << "El código hexadecimal debe tener 6 caracteres." << std::endl;
    }

    std::string hexR = hex.substr(0, 2);
    std::string hexG = hex.substr(2, 2);
    std::string hexB = hex.substr(4, 2);

    pwmR = hexaDeci(hexR);
    pwmG = hexaDeci(hexG);
    pwmB = hexaDeci(hexB);

    pwmR /= 255.0;
    pwmG /= 255.0;
    pwmB /= 255.0;

    red.write(1.0 - pwmR);
    green.write(1.0 - pwmG);
    blue.write(1.0 - pwmB);

}



int main() {
    

    while (true) {
        key = readKeyPad();
        if (key != NO_KEY) {
            std::cout << "Tecla presionada: " << key << std::endl;
            if (key == '1') {
                uno(key);
            }
            if (key == '2') {
                dos();
            }
            if (key == '3') {
                tres();
            }
        }
    }
    return 0;
}
