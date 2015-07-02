#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
public:
    Usuario();
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    void setClave(QString location);
    QString getClave() const;
    void setName(QString name);
    QString getName() const;
    void setId(int id);
    int getId() const;
    void setAcceso(int acceso);
    int getAcceso() const;
private:
    int id;
    QString name;
    QString clave;
    int acceso;
};

#endif // USUARIO_H
