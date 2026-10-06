#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "model.h"
#include "model19.h"
#include "model23.h"
#include "model37.h"


void runSimulation(Model& model, int n, const std::string& signalType, double amplitude, std::ofstream& csvFile) {
    for (int tau = 0; tau < n; ++tau) {
        double u = 0.0;

        if (signalType == "Step") {
            u = amplitude;
        }
        else if (signalType == "Pulse") {
            if (tau == 0) {
                u = amplitude;
            }
            else {
                u = 0.0;
            }
        }
        else if (signalType == "Harmonic") {
            u = amplitude * std::sin(tau);
        }

        double y = model.nextStep(u);

        std::cout << tau << "\t| " << u << "\t| " << y << "\n";

        csvFile << model.getName() << ";" << signalType << ";" << tau << ";" << u << ";" << y << "\n";
    }
}


int main() {
    std::ofstream csvFile("simulation_results.csv");

    if (!csvFile.is_open()) {
        std::cout << "Ошибка открытия файла.\n";
        return 1;
    }

    csvFile << "Model;SignalType;Step;U;Y\n";


    while (true) {

        int modelChoice;

        std::cout << "\n\n";
        std::cout << "============================================\n";
        std::cout << "     МОДЕЛИРОВАНИЕ УПРАВЛЯЕМОГО ОБЪЕКТА\n";
        std::cout << "============================================\n";

        std::cout << "Выберите модель:\n";
        std::cout << "1 - Модель 1.9\n";
        std::cout << "2 - Модель 2.3\n";
        std::cout << "3 - Модель 3.7\n";
        std::cout << "0 - Выход\n";

        std::cout << "Ваш выбор: ";
        std::cin >> modelChoice;


        if (modelChoice == 0) {
            break;
        }


        int signalChoice;
        std::string signalType;

        double amplitude;
        int n;


        // =========================================
        // МОДЕЛЬ 1.9
        // =========================================

        if (modelChoice == 1) {

            double a1;
            double a2;
            double a3;
            double b1;

            std::cout << "\n============================================\n";
            std::cout << "                 МОДЕЛЬ 1.9\n";
            std::cout << "============================================\n";

            std::cout << "Введите параметры модели:\n";

            std::cout << "a1 = ";
            std::cin >> a1;

            std::cout << "a2 = ";
            std::cin >> a2;

            std::cout << "a3 = ";
            std::cin >> a3;

            std::cout << "b1 = ";
            std::cin >> b1;


            std::cout << "\nВыберите входной сигнал:\n";
            std::cout << "1 - Ступенчатый\n";
            std::cout << "2 - Импульсный\n";
            std::cout << "3 - Гармонический\n";

            std::cout << "Ваш выбор: ";
            std::cin >> signalChoice;


            if (signalChoice == 1) {
                signalType = "Step";
            }
            else if (signalChoice == 2) {
                signalType = "Pulse";
            }
            else if (signalChoice == 3) {
                signalType = "Harmonic";
            }
            else {
                std::cout << "Неверный выбор сигнала.\n";
                continue;
            }


            std::cout << "\nАмплитуда сигнала A = ";
            std::cin >> amplitude;

            std::cout << "Количество шагов n = ";
            std::cin >> n;


            Model19 model(a1, a2, a3, b1);


            std::cout << "\n============================================\n";
            std::cout << "Модель: " << model.getName() << "\n";
            std::cout << "Сигнал: " << signalType << "\n";
            std::cout << "Амплитуда: " << amplitude << "\n";
            std::cout << "Количество шагов: " << n << "\n";
            std::cout << "============================================\n";

            std::cout << "tau\t| U\t| Y\n";
            std::cout << "--------------------------------------------\n";

            runSimulation(model, n, signalType, amplitude, csvFile);
        }


        // =========================================
        // МОДЕЛЬ 2.3
        // =========================================

        else if (modelChoice == 2) {

            double a;
            double b;
            double delta;

            std::cout << "\n============================================\n";
            std::cout << "                 МОДЕЛЬ 2.3\n";
            std::cout << "============================================\n";

            std::cout << "Введите параметры модели:\n";

            std::cout << "a = ";
            std::cin >> a;

            std::cout << "b = ";
            std::cin >> b;

            std::cout << "delta = ";
            std::cin >> delta;


            std::cout << "\nВыберите входной сигнал:\n";
            std::cout << "1 - Ступенчатый\n";
            std::cout << "2 - Импульсный\n";
            std::cout << "3 - Гармонический\n";

            std::cout << "Ваш выбор: ";
            std::cin >> signalChoice;


            if (signalChoice == 1) {
                signalType = "Step";
            }
            else if (signalChoice == 2) {
                signalType = "Pulse";
            }
            else if (signalChoice == 3) {
                signalType = "Harmonic";
            }
            else {
                std::cout << "Неверный выбор сигнала.\n";
                continue;
            }


            std::cout << "\nАмплитуда сигнала A = ";
            std::cin >> amplitude;

            std::cout << "Количество шагов n = ";
            std::cin >> n;


            Model23 model(a, b, delta);


            std::cout << "\n============================================\n";
            std::cout << "Модель: " << model.getName() << "\n";
            std::cout << "Сигнал: " << signalType << "\n";
            std::cout << "Амплитуда: " << amplitude << "\n";
            std::cout << "Количество шагов: " << n << "\n";
            std::cout << "============================================\n";

            std::cout << "tau\t| U\t| Y\n";
            std::cout << "--------------------------------------------\n";

            runSimulation(model, n, signalType, amplitude, csvFile);
        }


        // =========================================
        // МОДЕЛЬ 3.7
        // =========================================

        else if (modelChoice == 3) {

            double a;
            double b;
            double dt;

            std::cout << "\n============================================\n";
            std::cout << "                 МОДЕЛЬ 3.7\n";
            std::cout << "============================================\n";

            std::cout << "Введите параметры модели:\n";

            std::cout << "a = ";
            std::cin >> a;

            std::cout << "b = ";
            std::cin >> b;

            std::cout << "dt = ";
            std::cin >> dt;


            std::cout << "\nВыберите входной сигнал:\n";
            std::cout << "1 - Ступенчатый\n";
            std::cout << "2 - Импульсный\n";
            std::cout << "3 - Гармонический\n";

            std::cout << "Ваш выбор: ";
            std::cin >> signalChoice;


            if (signalChoice == 1) {
                signalType = "Step";
            }
            else if (signalChoice == 2) {
                signalType = "Pulse";
            }
            else if (signalChoice == 3) {
                signalType = "Harmonic";
            }
            else {
                std::cout << "Неверный выбор сигнала.\n";
                continue;
            }


            std::cout << "\nАмплитуда сигнала A = ";
            std::cin >> amplitude;

            std::cout << "Количество шагов n = ";
            std::cin >> n;


            Model37 model(a, b, dt);


            std::cout << "\n============================================\n";
            std::cout << "Модель: " << model.getName() << "\n";
            std::cout << "Сигнал: " << signalType << "\n";
            std::cout << "Амплитуда: " << amplitude << "\n";
            std::cout << "Количество шагов: " << n << "\n";
            std::cout << "============================================\n";

            std::cout << "tau\t| U\t| Y\n";
            std::cout << "--------------------------------------------\n";

            runSimulation(model, n, signalType, amplitude, csvFile);
        }


        else {
            std::cout << "\nНеверный выбор модели.\n";
            continue;
        }


        std::cout << "\n============================================\n";
        std::cout << "Моделирование завершено.\n";
        std::cout << "Результаты записаны в simulation_results.csv\n";
        std::cout << "============================================\n";
    }


    csvFile.close();

    std::cout << "\nПрограмма завершена.\n";

    return 0;
}