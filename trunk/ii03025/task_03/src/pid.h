#pragma once

/**
 * @brief Класс дискретного ПИД-регулятора.
 *
 * Реализует инкрементальный алгоритм ПИД-регулирования
 * с ограничением управляющего сигнала.
 */
class PIDController {

private:

    double kp;
    double ki;
    double kd;

    double uMin;
    double uMax;

    double previousError = 0.0;
    double previousPreviousError = 0.0;

    double control = 0.0;

public:

    /**
     * @brief Конструктор ПИД-регулятора.
     * @param p Пропорциональный коэффициент.
     * @param i Интегральный коэффициент.
     * @param d Дифференциальный коэффициент.
     * @param min Минимальное значение управляющего сигнала.
     * @param max Максимальное значение управляющего сигнала.
     */
    PIDController(double p, double i, double d,
                  double min, double max);

    /**
     * @brief Вычисляет новое управляющее воздействие.
     * @param setpoint Заданное значение.
     * @param output Текущее значение выхода объекта.
     * @param dt Шаг моделирования.
     * @return Новое управляющее воздействие.
     */
    double calculate(double setpoint, double output, double dt);

    /**
     * @brief Сбрасывает внутреннее состояние регулятора.
     */
    void reset();

};
