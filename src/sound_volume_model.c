#include <sound_manager.h>
#include <dlog.h>
#include "theatermode.h"
#include "sound_volume_model.h"

static void
sound_volume_model_print_model(SoundVolumeModel *model) {
	dlog_print(DLOG_DEBUG, LOG_TAG, "system:%d", model->system);
	dlog_print(DLOG_DEBUG, LOG_TAG, "notification:%d", model->notification);
	dlog_print(DLOG_DEBUG, LOG_TAG, "alarm:%d", model->alarm);
	dlog_print(DLOG_DEBUG, LOG_TAG, "media:%d", model->media);
	dlog_print(DLOG_DEBUG, LOG_TAG, "voice:%d", model->voice);
}

SoundVolumeModel *
sound_volume_model_get_current_volumes_n(void) {
	SoundVolumeModel *model = malloc(sizeof(SoundVolumeModel));
	sound_manager_get_volume(SOUND_TYPE_SYSTEM, &model->system);
	sound_manager_get_volume(SOUND_TYPE_NOTIFICATION, &model->notification);
	sound_manager_get_volume(SOUND_TYPE_ALARM, &model->alarm);
	sound_manager_get_volume(SOUND_TYPE_MEDIA, &model->media);
	sound_manager_get_volume(SOUND_TYPE_VOICE, &model->voice);

//	dlog_print(DLOG_DEBUG, LOG_TAG, "[sound_volume_model_get_current_volumes_n]");
//	sound_volume_model_print_model(model);

	return model;
}

void
sound_volume_model_set_current_volumes(SoundVolumeModel *model) {
//	dlog_print(DLOG_DEBUG, LOG_TAG, "[sound_volume_model_set_current_volumes]");
//	sound_volume_model_print_model(model);

	sound_manager_set_volume(SOUND_TYPE_SYSTEM, model->system);
	sound_manager_set_volume(SOUND_TYPE_NOTIFICATION, model->notification);
	sound_manager_set_volume(SOUND_TYPE_ALARM, model->alarm);
	sound_manager_set_volume(SOUND_TYPE_MEDIA, model->media);
	sound_manager_set_volume(SOUND_TYPE_VOICE, model->voice);
}

void
sound_volume_model_mute(void) {
	sound_manager_set_volume(SOUND_TYPE_SYSTEM, 0);
	sound_manager_set_volume(SOUND_TYPE_NOTIFICATION, 0);
	sound_manager_set_volume(SOUND_TYPE_ALARM, 0);
	sound_manager_set_volume(SOUND_TYPE_MEDIA, 0);
	sound_manager_set_volume(SOUND_TYPE_VOICE, 0);
}

