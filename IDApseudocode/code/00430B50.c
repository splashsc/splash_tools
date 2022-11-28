int __fastcall FBR_MD5Update(unsigned int *a1, int a2, unsigned int a3)
{
  unsigned int v3; // $v1
  unsigned int v5; // $a0
  int result; // $v0
  int v8; // $a1
  int v9; // $s5
  char *v10; // $v1
  unsigned __int8 *v11; // $a1
  char *v12; // $a3
  char v13[64]; // [sp+18h] [-44h] BYREF
  char v14; // [sp+58h] [-4h] BYREF

  v3 = *a1;
  v5 = 8 * a3 + *a1;
  result = (v3 >> 3) & 0x3F;
  if ( v5 < v3 )
    v8 = a1[1] + 1;
  else
    v8 = a1[1];
  *a1 = v5;
  a1[1] = (a3 >> 29) + v8;
  v9 = a2 + a3;
  while ( a2 != v9 )
  {
    while ( 1 )
    {
      ++a2;
      v10 = (char *)a1 + result++;
      v10[24] = *(_BYTE *)(a2 - 1);
      if ( result != 64 )
        break;
      v11 = (unsigned __int8 *)a1 + 26;
      v12 = v13;
      do
      {
        *(_DWORD *)v12 = (v11[1] << 24) | (*v11 << 16) | *(v11 - 2) | (*(v11 - 1) << 8);
        v12 += 4;
        v11 += 4;
      }
      while ( &v14 != v12 );
      ((void (__fastcall *)(unsigned int *, char *))loc_42FE80)(a1 + 2, v13);
      result = 0;
      if ( a2 == v9 )
        return result;
    }
  }
  return result;
}

