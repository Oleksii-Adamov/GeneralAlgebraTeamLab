#include "validation.h"
#include <QRegularExpressionValidator>

bool valid_ll(const QString& string) {
    QRegularExpression re("^-?[0-9]+$");
    return re.match(string).hasMatch();
}

bool valid_ull(const QString& string) {
    QRegularExpression re("^[0-9]+$");
    return re.match(string).hasMatch();
}
