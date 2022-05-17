#ifndef STQMAKEICON_HH
#define STQMAKEICON_HH

#include <QIcon>

/*!
 * \file
 *
 * \brief Funkcje generujące ikonki postępu
 *
 * Zawiera definicje funkcji tworzących ikonki postępu
 * sprawdzania sprawozdań
 */

namespace StQ {

  void MakeIcon4CheckProgress(QIcon &Icon4Progress, unsigned int Perc100);

}

#endif
