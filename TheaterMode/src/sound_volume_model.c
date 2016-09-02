#include <stdlib.h>
#include <sound_manager.h>
#include <dlog.h>
#include "theatermode.h"
#include "sound_volume_model.h"

SoundVolumeModel *
sound_volume_model_get_current_volumes_n(void) {
	SoundVolumeModel *model = malloc(sizeof(SoundVolumeModel));
	sound_manager_get_volume(SOUND_TYPE_SYSTEM, &model->system);
	sound_manager_get_volume(SOUND_TYPE_NOTIFICATION, &model->notification);
	sound_manager_get_volume(SOUND_TYPE_ALARM, &model->alarm);
	sound_manager_get_volume(SOUND_TYPE_RINGTONE, &model->ringtone);
	sound_manager_get_volume(SOUND_TYPE_MEDIA, &model->media);
	sound_manager_get_volume(SOUND_TYPE_VOICE, &model->voice);

	return model;
}

void
sound_volume_model_set_current_volumes(SoundVolumeModel *model) {
	sound_manager_set_volume(SOUND_TYPE_SYSTEM, model->system);
	sound_manager_set_volume(SOUND_TYPE_NOTIFICATION, model->notification);
	sound_manager_set_volume(SOUND_TYPE_ALARM, model->alarm);
	sound_manager_set_volume(SOUND_TYPE_RINGTONE, model->ringtone);
	sound_manager_set_volume(SOUND_TYPE_MEDIA, model->media);
	sound_manager_set_volume(SOUND_TYPE_VOICE, model->voice);
}

void
sound_volume_model_mute(void) {
	sound_manager_set_volume(SOUND_TYPE_SYSTEM, 0);
	sound_manager_set_volume(SOUND_TYPE_NOTIFICATION, 0);
	sound_manager_set_volume(SOUND_TYPE_ALARM, 0);
	sound_manager_set_volume(SOUND_TYPE_RINGTONE, 0);
	sound_manager_set_volume(SOUND_TYPE_MEDIA, 0);
	sound_manager_set_volume(SOUND_TYPE_VOICE, 0);
}
