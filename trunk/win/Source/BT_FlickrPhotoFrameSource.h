// Copyright 2012 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BT_FLICKR_PHOTO_FRAME_SOURCE
#define BT_FLICKR_PHOTO_FRAME_SOURCE

#include "BT_PhotoFrameSource.h"
#include "BT_RSSPhotoFrameSource.h"

class PbPhotoFrameSource;

#define FLICKR_AUTH_TOKEN "72157620687706465-4cd00281195a4fc5"

class FlickrPhotoFrameSource : public RSSPhotoFrameSource
{
	Q_DECLARE_TR_FUNCTIONS(FlickrPhotoFrameSource)

	QString		_userId;
	QString		_groupId;
	QString		_tag;

private:
	void createLocalCacheDirectory();
	void initialize(QString rssFeed);
	void printError(QString errorMessage);

public:
	FlickrPhotoFrameSource();
	FlickrPhotoFrameSource(QString rssFeed);

	virtual void requestSourceUpdate();
	virtual void onSourceUpdate(const FileTransfer& transfer);

	virtual void preparePhotoFrameDialog(PhotoFrameDialog * dialog) const;
	virtual bool unserialize(unsigned char *buf, uint &bufSz);
	virtual bool equals(PhotoFrameSource * other) const;
	virtual PhotoFrameSource * clone() const;

	virtual QString getName() const;
	virtual const PhotoFrameSourceType getType() const;

	QString getIdFromRSSFeed (QString rssFeed);
	QString getTagFromFlickrFeed (QString rssFeed);

	bool isValidFlickrPhotoFrame ();
	
	// protocol buffers
	virtual bool serializeToPb(PbPhotoFrameSource * pbSource);
	virtual bool deserializeFromPb(const PbPhotoFrameSource * pbSource);
};

#endif