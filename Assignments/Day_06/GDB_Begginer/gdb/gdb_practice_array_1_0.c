/******************************************************************************
rds                	:       gdb, practice

File Name               :       gdb_practice_array_1_0.c

Date of Creation        :       12/11/2007

Owner                   :       Sibu Cyriac

Date of Modification    :

Reason for modification :

Modifier                :

*******************************************************************************/

  Ideally two lists should be printed, but only one is printed.
  Debug the reason

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
 //#include <stdlib.h>

void * bsearch1(
        const void *key,
        const void *base0,
        size_t nmemb,
        size_t size,
        int (*compar)(const void *, const void *));

 void
 qsort1(
         void *a,
         size_t n, 
         size_t es,
         int (*cmp)(const void *, const void *));
         
/* Define an array of critters to sort. */

struct critter
  {
    const char *name;
    const char *species;
  };

struct critter muppets[] =
  {
    {"Kermit", "frog"},
    {"Daisy", "duck"},
    {"Gonzo", "whatever"},
    {"Fozzie", "bear"},
    {"Sam", "eagle"},
    {"Robin", "frog"},
    {"Animal", "animal"},
    {"Camilla", "chicken"},
    {"Sweetums", "monster"},
    {"Dr. Strangepork", "doc"},
    {"Link Hogthrob", "spy"},
    {"Zoot", "human"},
    {"Dr. Bunsen Honeydew", "human"},
    {"Beaker", "human"},
    {"Swedish Chef", "human"}
  };

int count = sizeof (muppets) / sizeof (struct critter);



/* This is the comparison function used for sorting and searching. */

int 
critter_cmp (const struct critter *c1, const struct critter *c2)
{
  return strcmp (c1->name, c2->name);
}


/* Print information about a critter. */

void 
print_critter (const struct critter *c)
{
  printf ("%s, the %s\n", c->name, c->species);
}


/* Do the lookup into the sorted array. */

void 
find_critter (const char *name)
{
  struct critter target, *result;
  target.name = name;
  result = bsearch1(&target, muppets, count, sizeof (struct critter),
                    critter_cmp);
  if (result)
    print_critter (result);
  else
    printf ("Couldn't find %s.\n", name);
}

/* Main program. */

int
main (void)
{
  int i;

  printf ("\n_______________________\n");
  while(i<count)
  {
    print_critter (&muppets[i]);
    i++;
  }
  printf ("\n");

  qsort1(muppets, count, sizeof (struct critter), critter_cmp);

  while(i<count)
  {
    print_critter (&muppets[i]);
  }
  printf ("\n");
  printf ("\n_______________________\n");

  printf ("\n");
  find_critter ("Kermit");
  find_critter ("Gonzo");
  find_critter ("Janice");

  return 0;
}

void * bsearch1(
        const void *key,
        const void *base0,
        size_t nmemb,
        size_t size,
        int (*compar)(const void *, const void *)) {

        register const char *base = base0;
        register size_t lim;
        register int cmp;
        register const void *p;

        for (lim = nmemb; lim != 0; lim >>= 1) {
                p = base + (lim >> 1) * size;
                cmp = (*compar)(key, p);
                if (cmp == 0)
                        return ((void *)p);
                if (cmp > 0) {  /* key > p: move right */
                        base = (char *)p + size;
                        lim--;
                }               /* else move left */
        }
        return (NULL);
}




 
 static inline char      *med3(char *, char *, char *, int (*)());
 static inline void       swapfunc(char *, char *, int, int);
 
 #define min(a, b)       (a) < (b) ? a : b
 
 /*
  * Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
  */
 #define swapcode(TYPE, parmi, parmj, n) {               \
         long i = (n) / sizeof (TYPE);                   \
         register TYPE *pi = (TYPE *) (parmi);           \
         register TYPE *pj = (TYPE *) (parmj);           \
         do {                                            \
                 register TYPE   t = *pi;                \
                 *pi++ = *pj;                            \
                 *pj++ = t;                              \
         } while (--i > 0);                              \
 }
 
 #define SWAPINIT(a, es) swaptype = ((char *)a - (char *)0) % sizeof(long) || \
         es % sizeof(long) ? 2 : es == sizeof(long)? 0 : 1;
 
 static inline void
 swapfunc(a, b, n, swaptype)
         char *a, *b;
         int n, swaptype;
 {
         if(swaptype <= 1) 
                 swapcode(long, a, b, n)
         else
                 swapcode(char, a, b, n)
 }
 
 #define swap(a, b)                                      \
         if (swaptype == 0) {                            \
                 long t = *(long *)(a);                  \
                 *(long *)(a) = *(long *)(b);            \
                 *(long *)(b) = t;                       \
         } else                                          \
                 swapfunc(a, b, es, swaptype)
 
 #define vecswap(a, b, n)        if ((n) > 0) swapfunc(a, b, n, swaptype)
 
 static inline char *
 med3(a, b, c, cmp)
         char *a, *b, *c;
         int (*cmp)();
 {
         return cmp(a, b) < 0 ?
                (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
               :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
 }
 
 void
 qsort1(a, n, es, cmp)
         void *a;
         size_t n, es;
         int (*cmp)(const void *, const void *);
 {
 char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
 int d, r, swaptype, swap_cnt;
 
 loop:   SWAPINIT(a, es);
 swap_cnt = 0;
 if (n < 7) {
 for (pm = (char *)a + es; pm < (char *) a + n * es; pm += es)
 for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0;
  pl -= es)
 swap(pl, pl - es);
 return;
 }
 pm = (char *)a + (n / 2) * es;
 if (n > 7) {
 pl = a;
 pn = (char *)a + (n - 1) * es;
 if (n > 40) {
 d = (n / 8) * es;
 pl = med3(pl, pl + d, pl + 2 * d, cmp);
 pm = med3(pm - d, pm, pm + d, cmp);
 pn = med3(pn - 2 * d, pn - d, pn, cmp);
 }
 pm = med3(pl, pm, pn, cmp);
 }
 swap(a, pm);
 pa = pb = (char *)a + es;
 
 pc = pd = (char *)a + (n - 1) * es;
 for (;;) {
 while (pb <= pc && (r = cmp(pb, a)) <= 0) {
 if (r == 0) {
 swap_cnt = 1;
 swap(pa, pb);
 pa += es;
 }
 pb += es;
 }
 while (pb <= pc && (r = cmp(pc, a)) >= 0) {
 if (r == 0) {
 swap_cnt = 1;
 swap(pc, pd);
 pd -= es;
 }
 pc -= es;
 }
 if (pb > pc)
 break;
 swap(pb, pc);
 swap_cnt = 1;
 pb += es;
 pc -= es;
 }
 if (swap_cnt == 0) {  /* Switch to insertion sort */
 for (pm = (char *)a + es; pm < (char *) a + n * es; pm += es)
 for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0; 
  pl -= es)
  swap(pl, pl - es);
 return;
 }
 
 pn = (char *)a + n * es;
 r = min(pa - (char *)a, pb - pa);
 vecswap(a, pb - r, r);
 r = min(pd - pc, pn - pd - es);
 vecswap(pb, pn - r, r);
 if ((r = pb - pa) > es)
 qsort1(a, r / es, es, cmp);
 if ((r = pd - pc) > es) { 
 /* Iterate rather than recurse to save stack space */
 a = pn - r;
 n = r / es;
 goto loop;
 }
 /*  qsort1(pn - r, r / es, es, cmp);*/
 }



/* References
http://fxr.watson.org
http://www.delorie.com/gnu
*/

