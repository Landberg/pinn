#ifndef OSINFO_H
#define OSINFO_H

/**
 * OS info model
 * Contains the information from os.json, and has a pointer to the partitions
 */

#include <QObject>
#include <QList>
#include <QVariantMap>
#include <QString>
#include <QStringList>

class PartitionInfo;

class OsInfo : public QObject
{
    Q_OBJECT
public:
    /* Constructor parses the json files in <folder>, and stores information in local variables */
    explicit OsInfo(const QString &folder, const QString & source, const QString &flavour = "", QObject *parent = 0);
    OsInfo();

    static bool _showAll;

    inline  QString folder()
    {
        return _folder;
    }

    inline QString flavour()
    {
        return _flavour;
    }

    inline QString name()
    {
        return _name;
    }

    inline QString description()
    {
        return _description;
    }

    inline QString version()
    {
        return _version;
    }

    inline QString releaseDate()
    {
        return _releaseDate;
    }

    inline bool bootable()
    {
        return _bootable;
    }

    inline QList<PartitionInfo *> *partitions()
    {
        return &_partitions;
    }

    inline int riscosOffset()
    {
        return _riscosOffset;
    }

    inline QString username()
    {
        return _username;
    }

    inline QString password()
    {
        return _password;
    }

    inline QString source()
    {
        return _source;
    }

    inline void setShowAll(bool all)
    {
        _showAll = all;
    }


    void importMap(QVariantMap& m);
    void importParts(QVariantList& parts);
    void print();

    bool canBootOs();
    bool canInstallOs();
    bool isSupportedOs();

protected:
    QString _folder, _flavour, _name, _description, _version, _releaseDate, _username, _password, _source;
    QString _icon, _osInfo, _partitionsInfo, _partitionSetup, _marketingInfo, _url;
    bool _bootable, _recommended;
    QList<PartitionInfo *> _partitions;
    QStringList _models;
    int _riscosOffset, _nominalSize;


};

#endif // OSINFO_H
