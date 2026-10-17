/* Prototype disponible :
   float cout_session(float puissance_kw, float duree_h, float tarif_kwh); */

float c1 = cout_session(22.0, 1.5, 0.22);   /* appel 1 */
float c2 = cout_session(0.22, 22.0, 1.5);   /* appel 2 */
float c3 = cout_session(22.0, 1.5);         /* appel 3 */
int   c4 = cout_session(22.0, 1.5, 0.22);   /* appel 4 */
