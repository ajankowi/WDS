#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGLViewer/qglviewer.h>
#include "mainwindow.h"
#include <QTranslator>

class Viewer;


/**
 * @brief Klasa Particle obsługuje tworzenie punktu
 */

class Particle {
public:
  Particle();

  /**
   * @brief inicjalizuje wszystkie punkty
   */
  void init();
  /**
   * @brief Wyrysowuje punkty w przestrzeni
   * @param[in] x,y,z - współrzędne punktu
   * @retval Ustawiany jest odpowiedni kolor punktów jak ich pozycja
   */
  void draw(bool special);
  /**
   * @brief pozycja punktu
   */
  qglviewer::Vec pos_;

private:
  qglviewer::Vec speed_;
  int age_, ageMax_;
};







/**
 * @brief Klasa obsługuje okno wyświetlające animację punktów
 */


class Viewer : public QGLViewer {

    /**
     * @brief Wskaźnik na wątek
     */
    WatekOdbioru *mOdbior;

    //MainWindow *te;

public:
    /**
     * @brief Inicjalizuje okno
     */
  Viewer(QWidget *parent);

protected:
  /**
   * @brief Metoda służy do rysowania obiektów w oknie
   * @param[out] Tablica punktów
   * @retval Tworzone są wszytskie punkty, nadawane są nim nazwy oraz rysowana jest
   * linia w momencie gdy urzytkownik wybierze dany punkt
   */
  virtual void draw();
  /**
   * @brief Metoda inicjalizująca
   * @param[out] Tablica punktów
   * @retval Ustawiany jest rozmiar punktów oraz rysowana jest siatka
   */
  virtual void init();
  /**
   * @brief Nadawanie nazw punktom
   * @param[out] Nazwy punktów
   * @retval Metoda ustawia każdemu punktowi indywidualną nazwe
   */
  virtual void drawWithNames();
  /**
   * @brief Rysowanie linii oraz przekazywanie współrzędnych punktu
   * @param[out] x,y,z - współrzędne punktu
   * @retval Metoda służy do wybierania danego punktu, zmienia jego kolor i wysyła jego koordynaty
   */
  virtual void postSelection(const QPoint &point);
  /**
   * @brief Instrukcja obsługi
   * @param[out] Nowe okno z instrukcją
   * @retval Metoda służy do wyświetlania instrukcji obsługi aplikacji
   */
  virtual QString helpString() const;

private:
  /**
   * @brief Zmienna przechowująca liczbę punktów
   */
  int nbPart_;
  /**
   * @brief Wskaźnik na klasę Particle
   */
  Particle *particle_;
  /**
   * @brief Wskaźnik na klasę Point
   */
  Punkt *point_;
  qglviewer::Vec selectedPoint, dir, orig;



public slots:
  /**
   * @brief Metoda służy do odbierania i zmiany współrzędnych punktów
   * @param[out] Nowo przesłane punkty
   * @retval Metoda służy do odbierania i zmiany współrzędnych punktów oraz zapisywaniu nich w tablicy
   */
    void onWspolrz(float,float,float);

};



#endif // ANIMATION_H
