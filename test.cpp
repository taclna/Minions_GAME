for (int i = 0; i < NUM_BIG_FISH; i++)
{
    Character[++NUM_CHARACTERS] = {BigFish[i].getLocation(), BigFish[i].getLevel(), BigFish[i].getFlip(), BigFish[i].getType()};
    BigFish[i].setNumOfCharacter(NUM_CHARACTERS);
    if (checkValidThreat(Character[NUM_CHARACTERS]))
    {
        validThreat.push_back(NUM_CHARACTERS);
    }
}