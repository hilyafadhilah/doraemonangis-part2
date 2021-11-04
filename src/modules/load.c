#include <stdio.h>
#include <ctype.h>
#include "load.h"
#include "../models/boolean.h"
#include "../models/config.h"
#include "../models/bangunan.h"
#include "../adt/wordmachine.h"
#include "../adt/point.h"
#include "../adt_modified/listpointdin.h"

boolean loadGame(char *filename, Config *conf)
{
  FILE *fp = fopen(filename, "r");

  int x, y, n, i, j;
  startWord(fp);

  // Ukuran map

  if (endWord || !wordToInt(currentWord, &(conf->mapRows)) ||
      conf->mapRows < 10 || conf->mapRows > 20)
  {
    return false;
  }
  advWord();

  if (endWord || !wordToInt(currentWord, &(conf->mapCols)) ||
      conf->mapCols < 10 || conf->mapCols > 30)
  {
    return false;
  }
  advWord();

  // Koordinat HQ

  if (endWord || !wordToInt(currentWord, &x))
  {
    return false;
  }
  advWord();

  if (endWord || !wordToInt(currentWord, &y))
  {
    return false;
  }
  advWord();

  conf->hq.label = '~';
  conf->hq.position = MakePOINT(x, y);

  // Lokasi

  // Jumlah lokasi
  if (endWord || !wordToInt(currentWord, &n))
  {
    return false;
  }
  advWord();

  CreateListDin(&(conf->bangunans), n);

  // List lokasi
  for (i = 0; i < n; i++)
  {
    Bangunan b;

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    advWord();

    b.label = currentWord.contents[0];

    if (endWord || !wordToInt(currentWord, &x))
    {
      return false;
    }
    advWord();

    if (endWord || !wordToInt(currentWord, &y))
    {
      return false;
    }
    advWord();

    b.position = MakePOINT(x, y);

    insertLast(&(conf->bangunans), b);
  }

  // Adjacency matrix

  int matSize = n + 1;
  CreateMatrix(matSize, matSize, &(conf->adjMatrix));

  for (i = 0; i < matSize; i++)
  {
    for (j = 0; j < matSize; j++)
    {
      if (endWord || !wordToInt(currentWord, &x))
      {
        return false;
      }
      advWord();

      ELMT(conf->adjMatrix, i, j) = x;
    }
  }

  // Pesanan

  // Jumlah pesanan
  if (endWord || !wordToInt(currentWord, &n))
  {
    return false;
  }
  advWord();

  // List pesanan
  for (i = 0; i < n; i++)
  {
    if (endWord || !wordToInt(currentWord, &x))
    {
      return false;
    }
    advWord();

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    advWord();

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    advWord();

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    advWord();
  }

  if (!endWord)
  {
    return false;
  }

  fclose(fp);
  return true;
}

boolean wordToStr(Word word, char *value)
{
  int i;
  for (i = 0; i < word.length; i++)
  {
    value[i] = word.contents[i];
  }
  value[i] = '\0';
}

boolean wordToInt(Word word, int *value)
{
  boolean status = false;

  if (word.length > 0)
  {
    *value = 0;
    status = true;

    int i = 0;
    if (word.contents[0] == '-')
    {
      ++i;
    }

    if (word.contents[i] == '0' && (i + 1) < word.length)
    {
      status = false;
    }
    else
    {
      while (i < word.length && status)
      {
        if (isdigit(word.contents[i]))
        {
          *value *= 10;
          *value += (int)(word.contents[i] - '0');
          ++i;
        }
        else
        {
          status = false;
        }
      }

      if (word.contents[0] == '-')
      {
        *value *= -1;
      }
    }
  }

  return status;
}