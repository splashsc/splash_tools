time_t get_sys_time()
{
  time_t v1; // [sp+18h] [-Ch] BYREF

  time(&v1);
  return v1;
}

