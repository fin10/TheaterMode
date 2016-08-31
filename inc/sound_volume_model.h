#ifndef SOUND_VOLUME_MODEL_H_
#define SOUND_VOLUME_MODEL_H_

typedef struct sound_volume_model {
	int system;
	int notification;
	int alarm;
	int ringtone;
	int media;
	int voice;
} SoundVolumeModel;

SoundVolumeModel *sound_volume_model_get_current_volumes_n(void);
void sound_volume_model_set_current_volumes(SoundVolumeModel *model);
void sound_volume_model_mute(void);

#endif /* SOUND_VOLUME_MODEL_H_ */
