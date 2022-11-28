int __fastcall asp_time(char *a1)
{
  struct tm *v2; // $v0
  char v4[64]; // [sp+18h] [-4Ch] BYREF
  time_t v5; // [sp+58h] [-Ch] BYREF

  v5 = time(0);
  v2 = localtime(&v5);
  strftime(v4, 0x40u, "%F %H:%M:%S", v2);
  return sprintf(a1, "%s", v4);
}

