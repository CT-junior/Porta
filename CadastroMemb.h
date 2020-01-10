#ifndef CADASTRO_MEMB_H
#define CADASTRO_MEMB_H

vector<Membros*> cadastra_membros(){
    vector<Membros*> memb;
    Membros *m;
    m = new Membros("CT", " 66 29 1A 9E", "ID_TELEGRAM", "CT");
    memb.push_back(m);
    m = new Membros("Alice", " 5B 81 C0 21", "ID_TELEGRAM", "Alice"); // Alana
    memb.push_back(m);
    m = new Membros("Artur", " ID_TAG", "ID_TELEGRAM", "Artur");
    memb.push_back(m);
    m = new Membros("Cecilia", " ID_TAG", "ID_TELEGRAM", "Cecilia");
    memb.push_back(m);
    m = new Membros("César", " ID_TAG", "ID_TELEGRAM", "Cesar");
    memb.push_back(m);
    m = new Membros("E. Laranja", " ID_TAG", "ID_TELEGRAM", "Emerson");
    memb.push_back(m);
    m = new Membros("Evandro", " 06 49 CC 8E", "ID_TELEGRAM", "Evandro");
    memb.push_back(m);
    m = new Membros("Felipe", " 4A 68 9E 07", "ID TELEGRAM 3", "Felipe"); // Guilherme
    memb.push_back(m);
    m = new Membros("Hector", " ID_TAG", "ID_TELEGRAM", "Hector");
    memb.push_back(m);
    m = new Membros("Isabel", " ID_TAG", "ID_TELEGRAM", "Isabel");
    memb.push_back(m);
    m = new Membros("Isabela B.", " ID_TAG", "ID_TELEGRAM", "Isabela Borges");
    memb.push_back(m);
    m = new Membros("Joana", " ID_TAG", "ID_TELEGRAM", "Joana");
    memb.push_back(m);
    m = new Membros("Juan", " ID_TAG", "ID_TELEGRAM", "Juan");
    memb.push_back(m);
    m = new Membros("Laila", " ID_TAG", "ID_TELEGRAM", "Laila");
    memb.push_back(m);
    m = new Membros("Larissa P.", " B9 08 96 6D", "ID_TELEGRAM", "Larissa Pais");
    memb.push_back(m);
    m = new Membros("Letícia", " 36 F7 11 9E", "ID_TELEGRAM", "Leticia");
    memb.push_back(m);
    m = new Membros("Mariana", " ID_TAG", "ID_TELEGRAM", "Mariana");
    memb.push_back(m);
    m = new Membros("Marina", " A5 A6 25 77", "ID_TELEGRAM", "Marina"); // Beatriz
    memb.push_back(m);
    m = new Membros("M. Deorce", " ID_TAG", "806101817", "Matheus Deorce");
    memb.push_back(m);
    m = new Membros("Miguel", " ID_TAG", "ID_TELEGRAM", "Miguel");
    memb.push_back(m);
    m = new Membros("Nicolle", " ID_TAG", "ID_TELEGRAM", "Nicolle");
    memb.push_back(m);
    m = new Membros("Rafaela", " ID_TAG", "ID_TELEGRAM", "Rafaela");
    memb.push_back(m);
    m = new Membros("Sara", " D6 A0 71 76", "ID_TELEGRAM", "Sara");
    memb.push_back(m);
    m = new Membros("Tiago B.", " C6 5B C5 8E", "ID_TELEGRAM", "Tiago Brito");
    memb.push_back(m);
    m = new Membros("Tiago T.", " ID_TAG", "ID_TELEGRAM", "Tiago Tessarolo");
    memb.push_back(m);
    m = new Membros("Victoria", " ID_TAG", "ID_TELEGRAM", "Nome_Firebase");
    memb.push_back(m);
    
    return memb;
}

#endif
