int *nvram_get()
{
  MEMORY[0]();
  return __errno_location();
}

