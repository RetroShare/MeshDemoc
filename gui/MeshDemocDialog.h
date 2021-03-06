/*
 * Retroshare MeshDemoc Dialog
 *
 * Copyright 2012-2012 by Robert Fernie.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License Version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA.
 *
 * Please report all bugs and problems to "retroshare@lunamutt.com".
 *
 */

#ifndef MRK_MESH_DEMOC_DIALOG_H
#define MRK_MESH_DEMOC_DIALOG_H

#include "gui/gxs/GxsGroupFrameDialog.h"

#define IMAGE_MESH_DEMOC ":/images/meshDemoc_32.png"

class MeshDemocDialog : public GxsGroupFrameDialog
{
	Q_OBJECT

public:
	/** Default Constructor */
	MeshDemocDialog(QWidget *parent = 0);
	/** Default Destructor */
	~MeshDemocDialog();

	virtual QIcon iconPixmap() const { return QIcon(IMAGE_MESH_DEMOC) ; } //MainPage
	virtual QString pageName() const { return tr("MeshDemoc") ; } //MainPage
	virtual QString helpText() const { return ""; } //MainPage

	virtual UserNotify *getUserNotify(QObject *parent);

	virtual void loadRequest(const TokenQueue *queue, const TokenRequest &req);

protected:
	virtual QString getHelpString() const ;
	virtual RetroShareLink::enumType getLinkType() { return RetroShareLink::TYPE_UNKNOWN; }
	virtual GroupFrameSettings::Type groupFrameSettingsType() { return GroupFrameSettings::Posted; }
	virtual void groupInfoToGroupItemInfo(const RsGroupMetaData &groupInfo, GroupItemInfo &groupItemInfo, const RsUserdata *userdata);

private:
	/* GxsGroupFrameDialog */
	virtual QString text(TextType type);
	virtual QString icon(IconType type);
	virtual QString settingsGroupName() { return "MeshDemocDialog"; }
	virtual GxsGroupDialog *createNewGroupDialog(TokenQueue *tokenQueue);
	virtual GxsGroupDialog *createGroupDialog(TokenQueue *tokenQueue, RsTokenService *tokenService, GxsGroupDialog::Mode mode, RsGxsGroupId groupId);
	virtual int shareKeyType();
	virtual GxsMessageFrameWidget *createMessageFrameWidget(const RsGxsGroupId &groupId);
	virtual RsGxsCommentService *getCommentService();
	virtual QWidget *createCommentHeaderWidget(const RsGxsGroupId &grpId, const RsGxsMessageId &msgId);
	virtual uint32_t requestGroupSummaryType() { return GXS_REQUEST_TYPE_GROUP_DATA; } // request complete group data
	virtual void loadGroupSummaryToken(const uint32_t &token, std::list<RsGroupMetaData> &groupInfo, RsUserdata* &userdata);
};

#endif
