#ifndef VALIDATION_H
#define VALIDATION_H
#include <QString>
#include <QRegularExpressionValidator>

bool valid_ll(const QString& string) {
    QRegularExpression re("^-?[0-9]+$");
    return re.match(string).hasMatch();
}

bool valid_ull(const QString& string) {
    QRegularExpression re("^[0-9]+$");
    return re.match(string).hasMatch();
}

#endif // VALIDATION_H
