bool validarEscolhaMedia(int n) {
    if(n < 3 || n > 7) {
        return true;
    }
    return false;
};

bool erroEscolhaCampeonato(int n) {
    if (n < 0 || n > 3) {
        return true;
    }
    return false;
};