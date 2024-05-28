# FileObserver
## Постановка задачи
Основное назначение приложения - отображение размера файлов в процентах, сгруппированных по двум стратегиям:

1. файлы сгруппированы по папкам:
2. файлы сгруппированы по типам.

## Часть 1
В первой части отдельным консольным приложением реализуем основную функцию –  вычисление размера, в зависимости от стратегии (см. Примерный вариант применения паттерна стратегии  ).

Общий принцип работы следующий: пользователь указывает директорию, для которой требуется вычислить размер содержимого.
Функция, в зависимости от выбранной стратегии, проводит вычисление, где результатом является набор соответствующих данных, вида

список файлов и папок (только верхнего уровня) / список типов файлов, содержащихся в директории(см. примеры в лекции ), а также занимаемый ими объём в процентах (точность два знака после запятой; если точности не хватает, а размер элемента не равен нулю, требуется это показать - например, в виде "< 0.01%").

Основная цель – проработка всевозможных условий. С целью доказательства того факта, что всевозможные условия обработаны, требуется подготовить тесты (примеры), на которых будете демонстрировать состоятельность вашей функции.

## UML
![alt text](https://github.com/lekksha/FileObserver/blob/main/UML.jpg)