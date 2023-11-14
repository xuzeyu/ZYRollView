//
//  WSLRollLabel_Cell.m
//  JSGL
//
//  Created by XUZY on 2021/10/29.
//

#import "WSLRollLabel_Cell.h"

@implementation WSLRollLabel_Cell

- (instancetype)initWithFrame:(CGRect)frame{
    if (self == [super initWithFrame:frame]) {
        self.contentView.clipsToBounds = YES;
        self.titleLabel = [[UILabel alloc] init];
        [self.contentView addSubview:self.titleLabel];
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(0);
            make.right.mas_equalTo(0);
            make.top.mas_equalTo(0);
            make.bottom.mas_equalTo(0);
        }];
    }
    return self;
}

- (void)setLabelEdge:(UIEdgeInsets)labelEdge {
    _labelEdge = labelEdge;
    [self.titleLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(labelEdge.left);
        make.right.mas_equalTo(-labelEdge.right);
        make.top.mas_equalTo(labelEdge.top);
        make.bottom.mas_equalTo(-labelEdge.bottom);
    }];
}

- (void)setLabelTop:(CGFloat)labelTop {
    _labelTop = labelTop;
    [self.titleLabel mas_updateConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(labelTop);
    }];
}

- (void)setLabelBottom:(CGFloat)labelBottom {
    _labelBottom = labelBottom;
    [self.titleLabel mas_updateConstraints:^(MASConstraintMaker *make) {
        make.bottom.mas_equalTo(-labelBottom);
    }];
}

- (void)setLabelLeft:(CGFloat)labelLeft {
    _labelLeft = labelLeft;
    [self.titleLabel mas_updateConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(labelLeft);
    }];
}

- (void)setLabelRight:(CGFloat)labelRight {
    _labelRight = labelRight;
    [self.titleLabel mas_updateConstraints:^(MASConstraintMaker *make) {
        make.right.mas_equalTo(-labelRight);
    }];
}

@end
