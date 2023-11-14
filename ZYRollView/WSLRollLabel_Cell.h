//
//  WSLRollLabel_Cell.h
//  JSGL
//
//  Created by XUZY on 2021/10/29.
//

#import "WSLRollView.h"

NS_ASSUME_NONNULL_BEGIN

@interface WSLRollLabel_Cell : WSLRollViewCell
@property (strong, nonatomic) UILabel * titleLabel;

@property (nonatomic, assign) UIEdgeInsets labelEdge;
@property (nonatomic, assign) CGFloat labelTop;
@property (nonatomic, assign) CGFloat labelBottom;
@property (nonatomic, assign) CGFloat labelLeft;
@property (nonatomic, assign) CGFloat labelRight;
@end

NS_ASSUME_NONNULL_END
