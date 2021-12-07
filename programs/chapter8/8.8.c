void Fill(CDC *pDC, POINT Seed,
          COLORREF BoundaryColor,
          COLORREF FillColor) {
    queue <POINT> Q;
    int maxsize = 0;
    Q.push(Seed);
    while (Q.size() > 0) {
        POINT p = Q.front();
        Q.pop();
        COLORREF pColor = pDC->GetPixel(p);
        if (pColor == FillColor || pColor == BoundaryColor) continue;
        pDC->SetPixel(p, FillColor);
        POINT ps[4] = {{p.x - 1, p.y},
                       {p.x + 1, p.y},
                       {p.x,     p.y + 1},
                       {p.x,     p.y - 1}};
        for (int i = 0; i < 4; i++) {
            pColor = pDC->GetPixel(ps[i]);
            if (pColor != BoundaryColor && pColor != FillColor)
                Q.push(ps[i]);
        }
    }
}
