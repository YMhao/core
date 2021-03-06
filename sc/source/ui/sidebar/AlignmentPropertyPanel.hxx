/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#ifndef INCLUDED_SC_SOURCE_UI_SIDEBAR_ALIGNMENTPROPERTYPANEL_HXX
#define INCLUDED_SC_SOURCE_UI_SIDEBAR_ALIGNMENTPROPERTYPANEL_HXX

#include <sfx2/sidebar/ControllerItem.hxx>
#include <sfx2/sidebar/IContextChangeReceiver.hxx>
#include <svx/sidebar/PanelLayout.hxx>
#include <vcl/fixed.hxx>
#include <vcl/button.hxx>
#include <vcl/layout.hxx>

class MetricField;
class MetricBox;

namespace sc { namespace sidebar {

class AlignmentPropertyPanel
:   public PanelLayout,
    public ::sfx2::sidebar::IContextChangeReceiver,
    public ::sfx2::sidebar::ControllerItem::ItemUpdateReceiverInterface
{
public:
    static VclPtr<vcl::Window> Create(
        vcl::Window* pParent,
        const css::uno::Reference<css::frame::XFrame>& rxFrame,
        SfxBindings* pBindings);

    virtual void DataChanged(
        const DataChangedEvent& rEvent) override;

    virtual void HandleContextChange(
        const vcl::EnumContext& rContext) override;

    virtual void NotifyItemUpdate(
        const sal_uInt16 nSId,
        const SfxItemState eState,
        const SfxPoolItem* pState,
        const bool bIsEnabled) override;

    SfxBindings* GetBindings() { return mpBindings;}

    // constructor/destructor
    AlignmentPropertyPanel(
        vcl::Window* pParent,
        const css::uno::Reference<css::frame::XFrame>& rxFrame,
        SfxBindings* pBindings);
    virtual ~AlignmentPropertyPanel() override;
    virtual void dispose() override;

private:
    //ui controls
    VclPtr<FixedText>                                  mpFTLeftIndent;
    VclPtr<MetricField>                                mpMFLeftIndent;
    VclPtr<CheckBox>                                   mpCBXWrapText;
    VclPtr<CheckBox>                                   mpCBXMergeCell;
    VclPtr<FixedText>                                  mpFtRotate;
    VclPtr<MetricBox>                                  mpMtrAngle;
    VclPtr<RadioButton>                                mpRefEdgeBottom;
    VclPtr<RadioButton>                                mpRefEdgeTop;
    VclPtr<RadioButton>                                mpRefEdgeStd;
    VclPtr<CheckBox>                                   mpCBStacked;
    VclPtr<VclHBox>                                    mpTextOrientBox;

    ::sfx2::sidebar::ControllerItem             maAlignHorControl;
    ::sfx2::sidebar::ControllerItem             maLeftIndentControl;
    ::sfx2::sidebar::ControllerItem             maMergeCellControl;
    ::sfx2::sidebar::ControllerItem             maWrapTextControl;
    ::sfx2::sidebar::ControllerItem             maAngleControl;
    ::sfx2::sidebar::ControllerItem             maVrtStackControl;
    ::sfx2::sidebar::ControllerItem             maRefEdgeControl;

    bool                                        mbMultiDisable : 1;

    vcl::EnumContext                            maContext;
    SfxBindings* const                          mpBindings;

    DECL_LINK( MFLeftIndentMdyHdl, Edit&, void );
    DECL_LINK( CBOXMergnCellClkHdl, Button*, void );
    DECL_LINK( CBOXWrapTextClkHdl, Button*, void );
    DECL_LINK( AngleModifiedHdl, Edit&, void );
    DECL_LINK( ClickStackHdl, Button*, void );
    DECL_LINK( ReferenceEdgeHdl, Button*, void );

    void Initialize();
    static void FormatDegrees(double& dTmp);
};

} } // end of namespace ::sc::sidebar

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
