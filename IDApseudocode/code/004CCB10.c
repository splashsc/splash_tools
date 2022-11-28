uint16_t htons(uint16_t hostshort)
{
  MEMORY[0](hostshort);
  return upgrade_prepare();
}
// 4CCB20: using guessed type int upgrade_prepare(void);

