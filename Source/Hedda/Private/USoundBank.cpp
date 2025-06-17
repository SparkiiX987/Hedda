#include "USoundBank.h"

USoundBase* UUSoundBank::GetSoundByName(FName _SoundName) const
{
	for (const FNamedSound& Sound : soundList)
	{
		if (Sound.SoundName == _SoundName)
		{
			return Sound.sound;
		}
	}
	return nullptr;
}