struct intdouble {
    bool intel;
    double d;
    int i;

    bool operator<(const intdouble &a) {
        if (this->intel && a.intel) return this->i < a.i;
        else if (!this->intel && !a.intel) return this->d < a.d;
        else if (!this->intel && a.intel) return this->d < (double) a.i;
        else if (this->intel && !a.intel) return (double) this->i < a.d;
    }

    void print(){
        if (this->intel) printf("%d ", this->i);
        else printf("%lf ",this->d);
    }
};
